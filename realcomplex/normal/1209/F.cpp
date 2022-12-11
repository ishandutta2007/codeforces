#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int ND = (int)6e6 + 9;
const int MOD = (int)1e9 + 7;
vector<pii> T[ND];
int cnt;

int sol[ND];



int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  cnt = n;
  int u, v;
  int x;
  int r;
  for(int i = 1 ; i <= m ; i ++ ){
    cin >> u >> v;
    r=u;
    x = i;
    vector<int> dig;
    while(x>0){
      dig.push_back(x%10);
      x/=10;
    }
    reverse(dig.begin(), dig.end());
    for(int j = 0 ; j < dig.size(); j ++ ){
      if(j + 1 == dig.size()){
        T[u].push_back(mp(v,dig[j]));
      }
      else{
        ++cnt;
        T[u].push_back(mp(cnt,dig[j]));
        u=cnt;
      }
    }
    u=r;
    swap(u,v);
    for(int j = 0 ; j < dig.size(); j ++ ){
      if(j + 1 == dig.size()){
        T[u].push_back(mp(v,dig[j]));
      }
      else{
        ++cnt;
        T[u].push_back(mp(cnt,dig[j]));
        u=cnt;
      }
    }
  }
  for(int i = 1; i <= cnt; i ++ )
    sol[i] = -1;
  sol[1] = 0;
  vector<pii> ord[2];
  ord[1].push_back(mp(0,1));
  vector<pii> edg;
  int c=0;
  int p = 0;
  while(!ord[1].empty()){
    swap(ord[1],ord[0]);
    ord[1].clear();
    for(int i = 0 ; i < ord[0].size(); i ++ ){
      for(auto x : T[ord[0][i].se]){
        edg.push_back(mp(x.se,x.fi));
      }
      if(i + 1 == ord[0].size() || ord[0][i].fi != ord[0][i+1].fi){
        sort(edg.begin(), edg.end());
        for(int j = 0 ; j < edg.size(); j ++ ){
          if(sol[edg[j].se] == -1){
            sol[edg[j].se] = ((sol[ord[0][i].se] * 10ll) % MOD + edg[j].fi) % MOD;
            ord[1].push_back(mp(c, edg[j].se));
          }
          if(j + 1 == edg.size() || edg[j].fi != edg[j+1].fi){
            c++;
          }
        }
        edg.clear();
      }
    }
    p ++ ;
  }
  for(int i = 2; i <= n; i ++ )
    cout << sol[i] << "\n";
  return 0;
}