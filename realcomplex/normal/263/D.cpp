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
#define ones(a) __builtin_popcount(a);

const int N = (int)1e5 + 9;
vector<int> T[N];
vector<int> pat;
bool vis[N];
int dz[N];

void dfs(int u){
  vis[u] = true;
  pat.push_back(u);
  for(auto x : T[u]){
    if(!vis[x]){
      dz[x] = dz[u] + 1;
      dfs(x);
      break;
    }
  }
}

int main(){
  fastIO;
  int n, m, k;
  cin >> n >> m >> k;
  int a, b;
  for(int i = 0;i < m;i ++ ){
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  dz[1] = 1;
  dfs(1);
  int las = pat.back();
  int mz = (int)1e9 + 9;
  int ix = 0;
  for(auto x : T[las]){
    if(dz[x] < mz){
      mz = dz[x];
      ix = x;
    }
  }
  vector<int> ans;
  for(int i = pat.size()-1;i >= 0;i -- ){
    ans.push_back(pat[i]);
    if(pat[i] == ix)
      break;
  }
  cout << ans.size() << "\n";
  for(auto x : ans)
    cout << x << " ";
  cout << "\n";
  return 0;
}