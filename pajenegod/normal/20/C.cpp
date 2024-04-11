// testing tarkus code
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<long long> vl;
typedef pair<int,long> pil;
typedef vector<pil> vil;

#define INF (long long)1E18
#define Nmax (long long)1E5

vii G[Nmax];   
vl Dist;  
vi tugfa;
 
void Dijkstra(int source, int N) {
    priority_queue<pil, vector<pil>, greater<pil>> Q;   
    Dist.assign(N,INF);
    Dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u]){
            int v = c.first;
            long long w = c.second;
            if(Dist[v] > Dist[u]+w){
                tugfa[v] = u;
                Dist[v] = Dist[u]+w;
                Q.push({Dist[v],v});
            }
        }
    }
}
 
int32_t main() {
    int N, M, u, v, w, source;  
    cin >> N >> M;
 
    for(int i=0;i<M;++i){
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    
    source = 0;
    tugfa.assign(N,-1);
    Dijkstra(source,N);
 
    vi out;
    int it=N-1;
    while (it!=-1){
        out.push_back(it);
        it=tugfa[it];
    }

    if(out.size()==0 || out.back()!=0){
        cout << -1 << endl;
    }else{
        reverse(out.begin(),out.end());
        for (auto node : out)
            cout<< node+1 << " ";
    }

    return 0;
}