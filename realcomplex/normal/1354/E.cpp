#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5010;
vector<int> T[N];
int bit[N];
bitset<N> f[2];
bitset<N> pt;
bitset<N> sol[N];
int s1, s2;

void dfs(int u, int cur){
  bit[u]=cur;
  f[cur][u]=1;
  if(cur == 0) s1 ++ ;
  else s2 ++ ;
  for(auto x : T[u]){
    if(bit[x]==-1){
      dfs(x,cur^1);
    }
    else{
      if(bit[x]==cur){
        cout << "NO\n";
        exit(0);
      }
    }
  }
}

int ans[N];


int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int n0, n1, n2;
  cin >> n0 >> n1 >> n2;
  int u, v;
  for(int i = 0; i < m ; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  for(int i = 1; i <= n; i ++ ) 
    bit[i]=-1;
  pt[0]=1;
  vector<int> nw;
  for(int i = 1; i <= n; i ++ ){
    if(bit[i]==-1){
      s1=0;
      s2=0;
      f[0].reset();
      f[1].reset();
      dfs(i,0);
      
      for(int j = n; j >= 0; j -- ){
        if(j >= s1 && pt[j - s1]){
          sol[j]=(sol[j - s1] | f[0]);
          pt[j]=1;
        }
        else if(j >= s2 && pt[j - s2]){
          sol[j]=(sol[j - s2] | f[1]);
          pt[j]=1;
        }
        else{
          sol[j].reset();
          pt[j]=0;
        }
      }
    }
  }
  if(pt[n1]){
    cout << "YES\n";
    for(int i = 1; i <= n; i ++ ){
      if(sol[n1][i]){
        cout << 2;
      }
      else{
        if(n0 > 0){
          n0--;
          cout << 1;
        }
        else{
          cout << 3;
        }
      }
    }
    cout << "\n";
  }
  else{
    cout << "NO\n";
  }
  return 0;
}