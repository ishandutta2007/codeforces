#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1010;

vector<pii> edg;
bool ban[N];
int deg[N];

int ask(int x, int y){
  cout << "? " << x << " " << y << "\n";
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}

int main(){
  int n;
  cin >> n;
  int cur = n;
  int u, v;
  for(int i = 1; i < n; i ++ ){
    cin >> u >> v;
    edg.push_back(mp(u,v));
  }
  int u1, v1;
  int lca;
  while(cur > 1){
    for(int i = 1; i <= n; i ++ ){
      deg[i]=0;
    }
    for(auto x : edg){
      if(!ban[x.fi] && !ban[x.se]){
        deg[x.fi] ++ ;
        deg[x.se] ++ ;
      }
    }
    u1 = 0, v1 = 0;
    for(int i = 1; i <= n; i ++ ){
      if(deg[i] == 1){
        if(u1 == 0) u1 = i;
        else if(v1 == 0) v1 = i;
      }
      
    }
    lca = ask(u1, v1);
    if(lca == u1 || lca == v1){
      cout << "! " << lca << "\n";
      fflush(stdout);
      return 0;
    }
    // so lazy
    ban[u1]=true;
    ban[v1]=true;
    cur -= 2;
  }
  for(int i = 1; i <= n; i ++ ){
    if(!ban[i]){
      cout << "! " << i << "\n";
      fflush(stdout);
      return 0;
    }
  }
  return 0;
}