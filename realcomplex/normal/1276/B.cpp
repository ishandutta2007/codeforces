#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const int M = (int)5e5 + 9;
vector<int> T[N];
bool vis[N];

int x, y;
void dfs(int u){
  vis[u]=true;
  for(auto p : T[u]){
    if(!vis[p])
      dfs(p);
  }
}

void solve(){
  int n, m;
  cin >> n >> m >> x >> y;
  for(int i = 1; i <= n; i ++ )
    T[i].clear();
  int a, b;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  vis[y]=true;
  dfs(x);
  ll p1 = 0, p2 = 0;
  for(int i = 1; i <= n; i ++ ){
    if(!vis[i])p1++;
    vis[i]=false;
  }
  vis[x]=true;
  dfs(y);
  for(int i = 1; i <= n; i ++ ){
    if(!vis[i])p2++;
    vis[i]=false;
  }
  cout << p1 * p2 << "\n";

}

int main(){
  fastIO;
  int tt;
  cin >> tt;
  for(int i = 0 ; i < tt; i ++ ){
    solve();
  }
  return 0;
}