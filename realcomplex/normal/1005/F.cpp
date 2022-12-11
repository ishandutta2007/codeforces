#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int N = (int)2e5 + 9;
vector<int> T[N];
int d[N];
int n;

void bfs(int u){
  for(int i = 1;i <= n;i ++ ){
    d[i] = 1234567;
  }
  d[u] = 0;
  queue<int> f;
  f.push(u);
  while(!f.empty()){
    u = f.front();
    f.pop();
    for(auto x : T[u]){
      if(d[u] + 1 < d[x]){
        d[x] = d[u] + 1;
        f.push(x);
      }
    }
  }
}

vector<int> nr[N];
int cnt[N];

int main(){
  int m, k;
  cin >> n >> m >> k;
  int u[m], v[m];
  for(int j = 0;j < m;j ++ ){
    cin >> u[j] >> v[j];
    T[u[j]].push_back(v[j]);
    T[v[j]].push_back(u[j]);
  }
  bfs(1);
  for(int j = 0;j < m;j ++ ){
    if(d[u[j]] + 1 == d[v[j]]){
      nr[v[j]].push_back(j);
    }
    if(d[v[j]] + 1 == d[u[j]]){
      nr[u[j]].push_back(j);
    }
  }
  string def;
  string res;
  vector<string> out;
  for(int i = 0;i < m;i ++ ){
    def.push_back('0');
  }
  bool is_sol;
  for(int i = 0;i < k;i ++ ){
    res = def;
    for(int j = 2;j <= n;j ++ ){
      res[nr[j][cnt[j]]] = '1';
    }
    out.push_back(res);
    is_sol = false;
    for(int j = 2;j <= n;j ++ ){
      if(cnt[j] + 1 < nr[j].size()){
        cnt[j] ++ ;
        is_sol = true;
        break;
      }
      else{
        cnt[j] = 0;
      }
    }
    if(!is_sol){
      break;
    }
  }
  cout << out.size() << "\n";
  for(auto x : out)
    cout << x << "\n";
  return 0;
}