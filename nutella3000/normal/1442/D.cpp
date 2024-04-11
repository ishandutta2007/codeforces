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
const int max_n = 3001;

int n, k;
vector<int> a[max_n];
int res = 0;

void relax(vector<int>& dp, int w, int c) {
    for(int i = k - w;i >= 0;i--)
        chkmax(dp[i + w], dp[i] + c);
}


void f(int l, int r, vector<int>& dp) {
    if (l == r) {
        for(int i = 0;i <= min(k, sz(a[l]) - 1);i++) {
            chkmax(res, a[l][i] + dp[k - i]);
        }
        return;
    }
    int m = (l + r) / 2;
    vector<int> le = dp, ri = dp;

    for(int i = l;i <= m;i++)
        relax(le, sz(a[i]) - 1, a[i].back());

    for(int i = m + 1;i <= r;i++)
        relax(ri, sz(a[i]) - 1, a[i].back());

    f(l, m, ri);
    f(m + 1, r, le);
}

void solve() {
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        a[i].emplace_back(0);
        int last = 0;
        int t;
        cin >> t;
        while(t--) {
            int v;
            cin >> v;
            last += v;
            a[i].emplace_back(last);
        }
    }

    vector<int> temp(k + 1, -inf);
    temp[0] = 0;
    f(0, n - 1, temp);

    cout << res;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}