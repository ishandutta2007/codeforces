#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back

mt19937 rnd(51);

int solve(int n, int m, int q, vector<pair<int,int>> u){
    map<pair<int,int>, int> mp, used;
    vector<pair<int,int>> need;
    for (auto to : u){
        mp[to] = 1;
    }
    deque<pair<int, pair<int,int>>> st{{0, {1, 1}}};
    int k = 2 + mp[{1, 1}];
    if (k <= n){
        used[{k, 1}] = 1;
        st.pb({1, {k, 1}});
    }
    if (k <= m){
        used[{1, k}] = 1;
        st.pb({1, {1, k}});
    }
    used[{1, 1}] = 1;
    while(st.size() > 0){
        int d = st.front().first, i = st.front().second.first, j = st.front().second.second;
        st.pop_front();
        if (i == n && j == m){
            return d;
        }
        int k = i + j + mp[{i, j}];
        if (k >= m){
            if (!used[{i, m}]){
                used[{i, m}] = 1;
                st.pb({d + 1, {i, m}});
            }
        }
        if (k >= n){
            if (!used[{n, j}]){
                used[{n, j}] = 1;
                st.pb({d + 1, {n, j}});
            }
        }
        if (abs(n - i) <= 2 * k){
            if (k <= m && !used[{i, k}]){
                used[{i, k}] = 1;
                st.pb({d + 1, {i, k}});
            }
        }
        if (abs(m - j) <= 2 * k){
            if (k <= n && !used[{k, j}]){
                used[{k, j}] = 1;
                st.pb({d + 1, {k, j}});
            }
        }
        if (i < j){
            if (k <= n && !used[{k, j}]){
                st.pb({d + 1, {k, j}});
                continue;
            }
            if (k <= m && !used[{i, k}]){
                used[{i, k}] = 1;
                st.pb({d + 1, {i, k}});
            }
        }
        else{
            if (k <= m && !used[{i, k}]){
                used[{i, k}] = 1;
                st.pb({d + 1, {i, k}});
                continue;
            }
            if (k <= n && !used[{k, j}]){
                used[{k, j}] = 1;
                st.pb({d + 1, {k, j}});
            }
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int,int>> u(q);
    for (int i = 0; i < q; i++){
        cin >> u[i].first >> u[i].second;
    }
    cout << solve(n, m, q, u) << endl;
    return 0;
}