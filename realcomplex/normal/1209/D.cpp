#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];

int sz = 0;
int edg = 0;
bool vis[N];

void dfs(int u){
  sz ++ ;
  vis[u] = true;
  for(auto x : T[u]){
    edg += (x > u);
    if(!vis[x]){
      dfs(x);
    }
  }
}

int main(){ 
  fastIO;
  int n, k;
  cin >> n >> k;
  int x, y;
  for(int i = 0; i < k; i ++ ){
    cin >> x >> y;
    T[x].push_back(y);
    T[y].push_back(x);
  }
  int res = 0;
  for(int i = 1; i <= n; i ++ ){
    if(!vis[i]){
      sz = 0;
      edg = 0;
      dfs(i);
      res += sz - 1;
    }
  }
  cout << k - res;
  return 0;
}