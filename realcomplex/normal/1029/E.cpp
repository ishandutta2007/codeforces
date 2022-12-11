#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)2e5 + 9;
vector<int> T[N];
int d[N];
int pr[N];

void dfs(int u, int par, int dep){
  d[u] = dep;
  pr[u] = par;
  for(auto x : T[u]){
    if(x != par)
      dfs(x, u, dep + 1);
  }
}

bool ok[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int u, v;
  for(int i = 1;i < n;i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  
  dfs(1, -1, 0);
  vector<pair<int, int>> dd;
  for(int i = 1;i <= n; i ++ ){
    if(d[i] > 2)
      dd.push_back(mp(d[i], i));
  }
  sort(dd.begin(), dd.end());
  int nod;
  int ans = 0;
  while(!dd.empty()){
    nod = dd.back().se;
    dd.pop_back();
    if(ok[nod]){
      continue;
    }
    ans ++ ;
    ok[nod] = true;
    nod = pr[nod];
    ok[nod] = true;
    for(auto x : T[nod]){
      ok[x] = true;
    }
  }
  cout << ans;
  return 0;
}