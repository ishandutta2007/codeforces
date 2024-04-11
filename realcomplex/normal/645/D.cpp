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
vector<int>order;
bool vis[N];

int u[N], v[N];
int n,m;
int mx[N];

void top_sort(int u){
  if(vis[u])
    return;
  vis[u] = true;
  for(auto x : T[u])
    top_sort(x);
  order.push_back(u);
}

bool is_ok(int ask){
  for(int i = 1;i <= n;i ++ )
    T[i].clear();
  memset(mx, 0, sizeof mx);
  for(int i = 0;i < ask;i ++ ){
    T[u[i]].push_back(v[i]);
  }
  memset(vis, false, sizeof vis);
  order.clear();
  for(int j = 1;j <= n;j ++ ){
    top_sort(j);
  }
  reverse(order.begin(), order.end());
  for(auto x : order){
    for(auto y : T[x]){
      mx[y] = max(mx[y], mx[x] + 1);
    }
  }
  for(int i = 1;i <= n;i ++ ){
    if(mx[i] == n-1)
      return true;
  }
  return false;
}

int main(){
  fastIO;
  cin >> n >> m;
  for(int i = 0;i < m;i ++ ){
    cin >> u[i] >> v[i];
  }
  int li = 0, ri = m;
  int md;
  while(li < ri){
    md = (li + ri) / 2;
    if(is_ok(md)){
      ri = md;
    }
    else{
      li = md+1;
    }
  }
  if(!is_ok(ri)){
    cout << -1;
    return 0; 
  }
  cout << ri;
  return 0;
}