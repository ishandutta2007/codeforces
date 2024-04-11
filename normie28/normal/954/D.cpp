#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
using namespace std;
typedef pair<int64_t, int64_t> P;
const int64_t INF = 1e18;
 
vector<int64_t> dijkstra(int N, int s, vector<P> edges[]){
    vector<int64_t> dist(N, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({0, s});
    while(que.size()){
        auto p = que.top(); que.pop();
        int i = p.second;
        int64_t d = p.first;
        if(d > dist[i]) continue;
        for(auto& e : edges[i]){
            int j = e.first;
            int64_t d2 = d + e.second;
            if(d2 < dist[j]){
                dist[j] = d2;
                que.push({d2, j});
            }
        }
    }
    return dist;
}
 
int main(){
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    S--; T--;
    vector<P> edges[1000];
    set<int> est[1000];
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        edges[a-1].emplace_back(b-1, 1);
        edges[b-1].emplace_back(a-1, 1);
        est[a-1].insert(b-1);
        est[b-1].insert(a-1);
    }
    auto ds = dijkstra(N, S, edges);
    auto dt = dijkstra(N, T, edges);
    int D = ds[T];
    int ans = 0;
    for(int i=0; i<N; i++) for(int j=0; j<i; j++){
        if(est[i].count(j)) continue;
        int d = 1 + min(ds[i] + dt[j], ds[j] + dt[i]);
        if(d >= D) ans++;
    }
    cout << ans << endl;
    return 0;
}