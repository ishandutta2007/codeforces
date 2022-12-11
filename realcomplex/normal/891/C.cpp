#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;
int u[N], v[N], w[N];
vector<int> ed[N];
vector<vector<pii>> qq[N];
int res[N];

int pi[N];
int sz[N];

int fin(int x){ 
  while(pi[x]!=x){
    x=pi[x];
  }
  return x;
}

bool rev;
vector<pii> ret;

bool unite(int a, int b){
  a = fin(a);
  b = fin(b);
  if(a == b) return false;
  if(sz[a] > sz[b]){
    swap(a,b);
  }
  if(rev)
    ret.push_back(mp(a,b));
  pi[a] = b;
  sz[b] += sz[a];
  return true;
}



int main(){
  fastIO;
  for(int i = 0 ; i < N ; i ++ ){
    pi[i] = i;
    sz[i] = 1;
  }
  int n, m;
  cin >> n >> m;
  for(int i = 1 ; i <= m ; i ++ ){
    cin >> u[i] >> v[i] >> w[i];
    ed[w[i]].push_back(i);
  }
  int q;
  cin >> q;
  int k;
  int id;
  for(int t = 0 ;t < q; t ++ ){
    cin >> k;
    res[t] = 1;
    for(int j = 0 ; j < k ; j ++ ){
      cin >> id;
      if(qq[w[id]].empty() || qq[w[id]].back().back().fi != t)
        qq[w[id]].push_back({mp(t,id)});
      else
        qq[w[id]].back().push_back(mp(t,id));
    }
  }
  for(int i = 1; i < N ; i ++ ){
    for(auto x : qq[i]){
      rev=true;
      for(auto y : x){
        if(!unite(u[y.se], v[y.se])){
          res[y.fi] = 0;
        }
      }
      while(!ret.empty()){
        sz[ret.back().se] -= sz[ret.back().fi];
        pi[ret.back().fi] = ret.back().fi;
        pi[ret.back().se] = ret.back().se;
        ret.pop_back();
      }
    }
    rev=false;
    for(auto x : ed[i]){
      unite(u[x], v[x]);
    }
  }
  for(int t = 0 ; t < q; t ++ ){
    if(res[t])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}