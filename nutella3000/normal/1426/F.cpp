#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;
 
const int inf = 1e15;
const int mod = 1e9 + 7;
const int max_n = 2e5 + 2;

int n;
string s;
int a[max_n], b[max_n];
int c = 1;

void solve() {
    cin >> n >> s;

    int res = 0;


    for(int i = 0;i < n;i++) {
        int mul = 1;
        if (s[i] == '?') mul = 3;

        if (i != 0) {
            a[i] = (a[i - 1] * mul + (s[i] == 'a' || mul == 3 ? c : 0)) % mod;

            b[i] = (b[i - 1] * mul + (s[i] == 'b' || mul == 3 ? a[i - 1] : 0)) % mod;

            res = (res * mul + (s[i] == 'c' || mul == 3 ? b[i - 1] : 0)) % mod;
        }else {
            a[i] = (s[i] == 'a' || mul == 3 ? c : 0);
        }

        c = c * mul % mod;

    }

    cout << res;
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}