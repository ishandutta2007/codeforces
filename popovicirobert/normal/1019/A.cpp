#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXM = 3000;

vector < pair <int, int> > v[MAXM + 1];
int pos[MAXM + 1], c[MAXM + 1];

bool cmp(int a, int b) {
    return c[a] < c[b];
}

bool vis[MAXM + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, p;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> p >> c[i];
        v[p].push_back({c[i], i});
        pos[i] = i;
    }
    sort(pos + 1, pos + n + 1, cmp);
    for(i = 1; i <= m; i++) {
        sort(v[i].begin(), v[i].end());
    }
    ll ans = 1e18;
    for(int nr = 1; nr <= n; nr++) {
        memset(vis, 0, sizeof(vis));
        for(auto it : v[1]) {
            vis[it.second] = 1;
        }
        int cnt = v[1].size();
        ll cur = 0;
        for(i = 2; i <= m; i++) {
            for(int j = 0; j <= (int) v[i].size() - nr; j++) {
                cur += v[i][j].first;
                vis[v[i][j].second] = 1;
                cnt++;
            }
        }
        for(i = 1; i <= n && cnt < nr; i++) {
            if(vis[pos[i]] == 0) {
                cnt++;
                cur += c[pos[i]];
            }
        }
        ans = min(ans, cur);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}