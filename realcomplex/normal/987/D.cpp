#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

const int N = (int)1e5 + 9;
vector<int>T[N];
vector<int>D[N];
int typ[N];
int vis[N];

int n;

void bfs(int ix){
  queue<int>has;
  for(int i = 0;i < N; i ++)
    vis[i] = (int)1e9 + 9;
  for(int i = 1;i <= n; i ++ ){
    if(typ[i] == ix){
      vis[i] = 0;
      has.push(i);
    }
  }
  int cur_node;
  while(!has.empty()){
    cur_node = has.front();
    D[cur_node].push_back(vis[cur_node]);
    has.pop();
    for(auto x : T[cur_node]){
      if(vis[cur_node] + 1 < vis[x]){
        vis[x] = vis[cur_node] + 1;
        has.push(x);
      }
    }
  }
}

int main(){
  fastIO;
  int m,s,k;
  cin >> n >> m >> k >> s;
  for(int i = 1; i <= n;i ++ )
    cin >> typ[i];
  int u,v;
  for(int i = 1;i <= m;i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  for(int i = 1;i <= k;i ++ )bfs(i);
  for(int i = 1;i <= n;i ++ )
    sort(D[i].begin(), D[i].end());
  int ans = 0;
  for(int i = 1;i <= n;i ++ ){
    ans = 0;
    for(int j = 0;j < s;j ++ )
      ans += D[i][j];
    cout << ans << " ";
  }
  return 0;
}