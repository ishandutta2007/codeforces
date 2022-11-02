#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

int n, x, pos, c1, c2;
int res = 1;

void bin() {
    int l = 0, r = n;
    while(l < r) {
        int m = (l + r) / 2;
        if (m <= pos) {
            l = m + 1;
            if (m < pos)
                res = res * c1-- % mod;
        }else {
            r = m;
            res = res * c2-- % mod;
        }
    }

    for(int i = 1;i <= c1 + c2;i++) {
        res = res * i % mod;
    }
}

void solve() {
    cin >> n >> x >> pos;
    c1 = x - 1;
    c2 = n - c1 - 1;
    bin();

    cout << res;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}