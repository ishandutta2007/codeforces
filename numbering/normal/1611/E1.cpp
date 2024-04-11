#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[200005];
vector<vector<int> > adj;
int dis[200005];
bool isleaf[200005];
int dis2[200005];
void dfs(int c, int p) {
    if(p != -1) dis2[c] = dis2[p] + 1;
    int cnt = 0;
    for(int n : adj[c]) {
        if(n == p) continue;
        dfs(n, c);
        cnt++;
    }
    if(cnt == 0 && c != 0) isleaf[c] = true;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, K;
        cin >> N >> K;
        fill(dis, dis + N, INF);
        fill(isleaf, isleaf + N, false);
        adj.clear();
        adj.resize(N);
        int i, j;
        queue<int> Q;
        for(i=0;i<K;i++) {
            cin >> j;
            j--;
            dis[j] = 0;
            Q.push(j);
        }
        int a, b;
        for(i=0;i<N-1;i++) {
            cin >>a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        while(!Q.empty()) {
            int t= Q.front();
            Q.pop();
            for(int n : adj[t]) {
                if(dis[n] > dis[t] + 1) {
                    dis[n] = dis[t] + 1;
                    Q.push(n);
                }
            }
        }
        dis2[0] = 0;
        dfs(0, -1);
        int isPos = false;
        for(i=0;i<N;i++) {
            if(isleaf[i] && dis2[i] < dis[i]) isPos = true;
        }
        if(isPos) cout << "YES\n";
        else cout << "NO\n";
    }
}