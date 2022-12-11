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

const int N = (int)2e5 + 91;
vector<int>G[N];
int tr[N];

int pos[N];
int ord[N];
int tt = 1;

void dfs(int u){
  pos[u] = tt;
  ord[tt] = u;
  tr[u] = 1;
  ++tt;
  for(auto x : G[u]){
    dfs(x);
    tr[u] += tr[x];
  }
}

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  int p;
  for(int i = 2;i <= n;i ++ ){
    cin >> p;
    G[p].push_back(i);
  }
  for(int j = 1;j <= n;j ++ ){
    sort(G[j].begin(), G[j].end());
  }
  dfs(1);
  int nod, sol;
  for(int i = 0;i < q;i ++ ){
    cin >> nod >> sol;
    if(tr[nod] < sol)
      cout << "-1\n";
    else
      cout << ord[pos[nod] + sol - 1] << "\n";
  }
  return 0;
}