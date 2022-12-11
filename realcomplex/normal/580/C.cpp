#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)1e5 + 9;
vector<int>T[N];
bool vis[N];
int m;
int cc[N];
int ans = 0;

void dfs(int u, int cats){
  if(cc[u] == 1)
    cats ++ ;
  else
    cats = 0;
  if(cats > m)
    return;
  vis[u] = true;
  int p = 0;
  for(auto x : T[u]){
    if(!vis[x]){
      dfs(x, cats);
      p ++ ;
    }
  }
  if(p==0)
    ans ++ ;
}

int main(){
  fastIO;
  int n;
  cin >> n >> m;
  for(int i = 1;i <= n;i ++ )
    cin >> cc[i];
  int u, v;
  for(int i = 1;i < n;i ++) {
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans << "\n";
  return 0;
}