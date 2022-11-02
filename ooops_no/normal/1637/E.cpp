#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 3e5 + 10;
vector<int> all[N];

long long smart_solve(int n, int m, vector<int> a, vector<pair<int,int>> bad) {
    map<pair<int,int>, int> mp;
    map<int,int> cnt;
    set<int> st;
    for (auto to : bad) {
        mp[{to.first, to.second}] = mp[{to.second, to.first}] = 1;
    }
    for (auto to : a) {
        cnt[to]++;
        st.insert(to);
    }
    if (st.size() == 1) {
        return 0;
    }
    vector<int> u;
    for (auto to : cnt) {
        u.pb(to.second);
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    int k = u.size();
    for (int i = 0; i < k; i++) all[i].clear();
    for (auto to : st) {
        all[lower_bound(u.begin(), u.end(), cnt[to]) - u.begin()].pb(to);
    }
    for (int i = 0; i < k; i++) {
        sort(all[i].rbegin(), all[i].rend());
    }
    long long ans = 0;
    for (auto i : st) {
        int kol = cnt[i];
        for (int j = 0; j < k; ++j) {
            for (int f = 0; f < all[j].size(); ++f) {
                if (mp.find({i, all[j][f]}) == mp.end() && i != all[j][f]) {
                    ans = max(ans, 1ll * (kol + u[j]) * 1ll * (i + all[j][f]));
                    break;
                }
            }
        }
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<pair<int,int>> u(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> u[i].first >> u[i].second;
        }
        cout << smart_solve(n, m, a, u) << endl;
    }
    return 0;
}