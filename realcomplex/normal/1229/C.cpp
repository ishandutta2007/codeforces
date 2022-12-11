#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 1;
const int B = 300;
vector<int> T[N];
vector<int> R[N];
ll deg[N];
ll b[N];
ll u[N], v[N];

vector<ll> ask;
ll did[N];

ll f[B + 55];

void add(int li, ll di){
  f[li] += di;
}

ll sal[N];

int main(){
  fastIO;
  ll n, m;
  cin >> n >> m;
  for(int i = 0 ;i  <m ; i ++ ){
    cin >> u[i] >> v[i];
    deg[u[i]] ++ ;
    deg[v[i]] ++ ;
    if(u[i] > v[i]) swap(u[i], v[i]);
      b[v[i]] ++ ;
    T[u[i]].push_back(v[i]);
    T[v[i]].push_back(u[i]);
  }
  ll res = 0;
  for(int i = 1; i <= n; i ++ ){
    res += (deg[i] - b[i]) * 1ll * b[i];
    sal[i] = i;
  }
  cout << res << "\n";
  int q;
  cin >> q;
  int l=0,r;
  int v;
  while(l < q){
    r = min(q-1, l+B-1);
    for(int i = 0 ;i <= B;i ++ )
      f[i] = 0;
    ask.clear();
    for(int i = 1; i <= n; i ++ ){
      did[i] = -1;
      R[i].clear();
    }
    for(int t = l; t <= r; t ++ ){
      cin >> v;
      ask.push_back(v);
    }
    for(int i = (int)ask.size() - 1; i >= 0 ; i -- ){
      did[ask[i]] = i;
    }
    for(int i = 1; i <= n; i ++ ){
      if(did[i] != -1){
        for(auto x : T[i]){
          if(did[x] != -1){
            R[i].push_back(x);
          }
        }
      }
    }
    for(int i = 1; i <= n; i ++ ){
      if(did[i] != -1) continue;
      vector<int> tt;
      for(auto x : T[i]){
        if(did[x] != -1){
          if(sal[i] > sal[x])
            tt.push_back(did[x]);
        }
      }
      sort(tt.begin(), tt.end());
      for(auto x : tt){
        add(x, -(deg[i]-b[i])*1ll*b[i]);
        b[i] -- ;
        add(x, (deg[i]-b[i])*1ll*b[i]);
      }
    }
    for(int i = 0 ; i < ask.size(); i ++ ){
      add(i, -(deg[ask[i]]-b[ask[i]])*1ll*b[ask[i]]);
      b[ask[i]] = deg[ask[i]];
      for(auto x : R[ask[i]]){
        if(sal[ask[i]] < sal[x]){
          add(i, -(deg[x]-b[x])*1ll*b[x]);
          b[x] -- ;
          add(i, (deg[x]-b[x])*1ll*b[x]);
        }
      }
      sal[ask[i]] = n + l + i + 1;
    }
    
    for(int i = l ; i <= r; i ++ ){
      res += f[i-l];
      cout << res << "\n";
    }
    l += B;
  }
  return 0;
}