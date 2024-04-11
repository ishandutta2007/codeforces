#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e5;

int p2[MAXN + 1], sp[MAXN + 1];
char str[MAXN + 1];

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    cin >> str + 1;
    for(i = 1; i <= n; i++) {
        sp[i] = sp[i - 1] + (str[i] == '1');
    }
    int pw = 2;
    p2[0] = 1;
    for(i = 1; i <= n; i++) {
        p2[i] = (1LL * p2[i - 1] + pw) % MOD;
        pw *= 2;
        if(pw >= MOD)
            pw -= MOD;
    }
    while(q > 0) {
        q--;
        int l, r;
        cin >> l >> r;
        int cnt = sp[r] - sp[l - 1];
        cout << (p2[r - l] - p2[r - l - cnt] + MOD) % MOD << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}