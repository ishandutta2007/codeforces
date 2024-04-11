#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
const int INF = 1e18;
vector<vector<int>> adj;
map<P,int> M2;
int dis[200005];
bool vis[200005];
int ord[200005];
int cnt1[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    int i, j;
    adj.resize(N);
    for(i=0;i<M;i++) {
        int a, b;
        cin >> a >> b;
        adj[b-1].push_back(a-1);
        ord[a-1]++;
        M2[P(b-1,a-1)]++;
    }
    for(i=0;i<N;i++) dis[i] = INF;
    for(i=0;i<N;i++) vis[i] = false;
    dis[N-1] = 0;
    priority_queue<P, vector<P>, greater<P>> PQ;
    PQ.push(P(0,N-1));
    while(!PQ.empty()) {
        P c2 = PQ.top();
        PQ.pop();
        if(vis[c2.second]) continue;
        vis[c2.second] = true;
        int d = c2.first, id = c2.second;
        for(int n : adj[id]) {
            cnt1[n] += M2[P(id,n)];
            M2[P(id,n)] = 0;
            //cout << n << " : " << id << ' ' << dis[id] + ord[n] + 1 - cnt1[n] << '\n';
            if(dis[n]>dis[id]+ord[n]+1-cnt1[n]) {
                dis[n] = dis[id] + ord[n]+1-cnt1[n];
                PQ.push(P(dis[n],n));
            }
        }
    }
    cout << dis[0];
}