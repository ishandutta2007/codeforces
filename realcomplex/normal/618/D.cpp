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

const int N = (int)2e5 + 9;
vector<int>T[N];
bool vis[N];
int can[N];

int max_cover = 0;

void dfs(int u){
  can[u] = 2;
  vis[u] = true;
  for(auto x : T[u]){
    if(vis[x]){
      continue;
    }
    dfs(x);
    if(can[u] > 0 and can[x] > 0){
      can[u] -- ;
      max_cover ++ ;
    } 
  }
}

int main(){
  fastIO;
  int n,x,y;
  cin >> n >> x >> y;
  int u, v;
  for(int i = 1;i < n;i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  if(x > y){
    bool star = false;
    for(int i = 1;i <= n;i ++ )
      if(T[i].size() == n - 1)
        star = true;
    if(star){
      cout << 1LL * y * (n-2) + 1LL * x;
    }
    else{
      cout << 1LL * y * (n-1) ;
    }
    cout << "\n";
    exit(0);
  }
  dfs(1);
  int ok = max_cover;
  ll rz = 1LL * ok * x;
  rz += 1LL * (n - 1 - ok) * y;
  cout << rz;
  return 0;
}