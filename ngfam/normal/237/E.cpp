#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 110;

struct MinCostFlow{
  struct Edge{
    int vertice;
    int flow;
    int lim;
    int cost;
    Edge* rev;
  };

  int Path[N];
  int Delta[N];
  int inQueue[N];
  list < Edge > adj[N];
  int MaxFlow = 0, MaxCost = 0, Size = 0;

  Edge NewEdge(int v, int lim, int cost){
    Edge x;
    x.vertice = v;
    x.lim = lim;
    x.flow = 0;
    x.cost = cost;
    return x;
  }

  void addEdge(int u, int v, int lim, int cost){
    Size = max(Size, v);
    Size = max(Size, u);
    adj[u].push_back(NewEdge(v, lim, cost));
    adj[v].push_back(NewEdge(u, 0, -cost));
    adj[u].back().rev = &adj[v].back();
    adj[v].back().rev = &adj[u].back();
  }

  void Solve(int From, int To){
    while(true){
      fill(Path + 1, Path + Size + 1, 1e9);
      fill(inQueue + 1, inQueue + Size + 1, 0);
      fill(Delta + 1, Delta + Size + 1, 0);
      queue < int > Queue;
      vector < list < Edge > :: iterator > Prev(Size + 10);
      Queue.push(From);
      Path[From] = 0;
      Delta[From] = 1e9;
      inQueue[From] = 1;
      while(!Queue.empty()){
        int u = Queue.front();
        Queue.pop();
        inQueue[u] = 0;

        for(auto it = adj[u].begin(); it != adj[u].end(); ++it){
          #define Curr (*it)
          if(Curr.lim - Curr.flow <= 0){
            continue;
          }
          int newCost = Path[u] + Curr.cost;
          if(Path[Curr.vertice] > newCost){
            Path[Curr.vertice] = newCost;
            Prev[Curr.vertice] = it;
            Delta[Curr.vertice] = min(Delta[u], Curr.lim - Curr.flow);
            if(!inQueue[Curr.vertice]){
              inQueue[Curr.vertice] = 1;
              Queue.push(Curr.vertice);
            }
          }
        }
      }
      if(Delta[To] == 0){
        break;
      }
      int x = To;
      MaxFlow += Delta[x];
      MaxCost += Path[x] * Delta[x];
      while(x != From){
        Prev[x] -> flow += Delta[To];
        Prev[x] -> rev -> flow -= Delta[To];
        x = Prev[x] -> rev -> vertice;
      }
    }
  }
}MinCostFlow;

int n, len;
char a[N];
int cnt[N];
char Read[M];


int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%s", a + 1);
  len = strlen(a + 1);
  for(int i = 1; i <= len; ++i){
    ++cnt[a[i] - 'a'];
  }
  for(int i = 0; i < 26; ++i){
    MinCostFlow.addEdge(3 + i, 2, cnt[i], 0);
  }
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int Value;
    scanf("%s%d", Read + 1, &Value);
    MinCostFlow.addEdge(1, 28 + i, Value, 0);
    int len = strlen(Read + 1);
    for(int x = 1; x <= len; ++x){
      MinCostFlow.addEdge(28 + i, 3 + Read[x] - 'a', 1, i);
    }
  }

  MinCostFlow.Solve(1, 2);
  if(MinCostFlow.MaxFlow < len){
    puts("-1");
  }
  else{
    cout << MinCostFlow.MaxCost;
  }
  return 0;
}