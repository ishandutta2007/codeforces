#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

string s;
string t[N];
int n;
long long shift[10], val[10];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> s;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 0; i < 10; i++) shift[i] = 10, val[i] = i;
    for(int i = n; i; i--) {
        long long sh = 1, va = 0;
        for(int j = (int)t[i].size() - 1; j >= 3; j--) {
            va = (va + val[t[i][j] - '0'] * sh % MOD) % MOD;
            sh = sh * shift[t[i][j] - '0'] % MOD;
        }
        val[t[i][0] - '0'] = va;
        shift[t[i][0] - '0'] = sh;
    }
    long long res = 0;
    for(int i = 0; i < (int)s.size(); i++)
        res = (res * shift[s[i] - '0'] + val[s[i] - '0']) % MOD;
    cout << res;
    return 0;
}