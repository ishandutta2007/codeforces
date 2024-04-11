#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100001;
const long long  MAX = 123456897213124;

int n, m, k, ans;
vector < pair <int, long long> > a[N];
priority_queue < pair<long long ,int > > q;
bool Visited[N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v;
        long long x;
        cin >> u >> v >> x;
        a[u].push_back(make_pair(v, x));
        a[v].push_back(make_pair(u, x));
    }
    for(int i = 1; i <= k; i++) {
        int u;
        long long x;
        cin >> u >> x;
        q.push(make_pair(-x, u - N));
    }
    q.push(make_pair(0, 1));
    while(!q.empty()) {
        pair<long long, int> u = q.top();
        q.pop();
        if(u.second < 0) {
            u.second += N;
            if(Visited[u.second]) ans++;
        }
        if(Visited[u.second]) continue;
        Visited[u.second] = 1;
        for(int i = 0; i < (int)a[u.second].size(); i++)
            q.push(make_pair(u.first - a[u.second][i].second, a[u.second][i].first));
    }
    cout << ans;
    return 0;
}