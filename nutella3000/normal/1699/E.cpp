#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;

void run() {
    int n, m; cin >> n >> m; ++m;
    vector<bool> a(m);
    for (int i = 0; i < n; ++i) {
        int v; cin >> v; a[v] = true;
    }
    vector<int> dp(m, m-1);
    vector<int> cnt(m);
    cnt[m-1] = count(all(a), 1);


    int mn_el = find(all(a), 1) - a.begin();
    int res = inf, R = m-1;

    auto func = [&](int id, int v) {
        if (dp[id] <= v) return false;
        if (a[id]) --cnt[dp[id]];
        dp[id] = v;
        if (a[id]) ++cnt[dp[id]];
        return true;
    };

    for (int L = m-1; L >= 1; --L) {
        func(L, L);

        for (int i = L*L; i < m; i += L)
            func(i, max(dp[L], dp[i/L]));
        
        while (!cnt[R]) --R;
        if (L <= mn_el) chmin(res, R-L);
    }

    cout << res << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}