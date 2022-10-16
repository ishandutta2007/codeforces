#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
vector<pair<int, int> > adj[maxn];
long long longest[maxn], mxx[maxn];
pair<long long, int> far1[maxn], far2[maxn], far3[maxn], far4[maxn];
long long res;
int n;
void DFS(int u, int p = -1) {
    longest[u] = 0;
    far1[u] =  {0, u};
    far2[u] = far3[u] = far4[u] = {0, 0};
    for (auto x : adj[u]) {
        int v = x.first, w = x.second;
        if (v == p) continue;
        DFS(v, u);
        mxx[u] = max(mxx[u], mxx[v]);
        pair<long long, int> cur = far1[v];
        cur.second = v;
        cur.first += w;
        if (cur.first > far1[u].first)
            far4[u] = far3[u],
            far3[u] = far2[u],
            far2[u] = far1[u],
            far1[u] = cur;
        else if (cur.first > far2[u].first)
            far4[u] = far3[u],
            far3[u] = far2[u],
            far2[u] = cur;
        else if (cur.first > far3[u].first)
            far4[u] = far3[u],
            far3[u] = cur;
        else if (cur.first > far4[u].first) 
            far4[u] = cur;
        longest[u] = max(longest[u], longest[v]);
    }
    longest[u] = max(longest[u], far1[u].first + far2[u].first);
    res = max(res, far1[u].first + far2[u].first + far3[u].first + far4[u].first);

    mxx[u] = max(mxx[u], longest[u]);
}

void re_DFS(int u, int p = -1, int prw = 0, long long far_from_home = 0, long long longest_from_home = 0) {
    vector<pair<long long, int> > f;
    for (auto x : adj[u]) if (x.first != p)
        f.push_back({longest[x.first], x.first});

    res = max(res, mxx[u] + longest_from_home + 2*prw);
    res = max(res, far1[u].first + far2[u].first + far3[u].first + far_from_home);

    sort(f.rbegin(), f.rend());
    for (auto x : adj[u]) {
        int v = x.first, w = x.second;
        if (v == p) continue;
        // cut edge (u, v)
        long long fi = far1[u].first;
        long long se = far2[u].first;
        if (far1[u].second == v)
            fi = far3[u].first;
        if (far2[u].second == v)
            se = far3[u].first;
        if (fi < se) swap(se, fi);
        if (far_from_home > fi)
            se = fi,
            fi = far_from_home;
        else if (far_from_home > se)
            se = far_from_home;
        long long cur_long = max(longest_from_home, fi + se);
        for (int i = 0; i < f.size(); ++i) {
            if (f[i].second != v) {
                cur_long = max(cur_long, f[i].first);
                break;
            }
        }
        re_DFS(v, u, w, fi + w, cur_long);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long sum = 0;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p, w, x;
        cin >> p >> w >> x; sum += x;
        adj[p].push_back({w, x});
        adj[w].push_back({p, x});
    }

    res = 0;
    DFS(1);
    re_DFS(1);
    
    cout << sum*2 - res << '\n';
 
    return 0;
}