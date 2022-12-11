#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int bl = 700;

vector<int> nx[N];
int pi[N];

int dp[N][500];

int lg[N]; 


int main(){
  fastIO;
  for(int i = 0 ; i < N ; i ++ )
    pi[i] = -1;
  lg[0] = 0;
  for(int i = 1 ; i < N ; i ++ ){
    lg[i] = lg[i-1];
    while((1 << (lg[i] + 1)) <= i){
      lg[i] ++ ;
    }
  }
  int n, m;
  cin >> n >> m;
  int l, r;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> l >> r;
    nx[l].push_back(r);
    pi[r] = l;
  }
  for(int i = 1; i <= n; i ++ )
    for(int j = 0 ; j < 500; j ++ )
      dp[i][j] = i;
  int rf;
  int id;
  int sz;
  int mx;
  for(int x = 1 ; x * bl <= n; x ++ ){
    rf = x * bl;
    vector<pii> p;
    for(int i = rf; i >= 1; i -- ){
      sz = p.size();
      id = sz;
      mx = i;
      for(auto t : nx[i]){
        if(t <= rf)
          mx = max(mx, t);
      }
      for(int j = lg[sz] ; j >= 0 ; j -- ){
        if(id - (1 << j) < 0 || p[id - (1 << j)].se > mx) continue;
        id -= (1 << j);
      }
      if(id != sz){
        dp[i][x] = p[id].fi;
      }
      while(!p.empty() && p.back().fi <= dp[i][x]){
        p.pop_back();
      }
      p.push_back(mp(dp[i][x], i));
    }

  }
  int q;
  cin >> q;
  int t;
  int pp;
  int li;
  for(int i = 0 ; i < q; i ++ ){
    cin >> l >> r;
    t = -1;
    for(int j = l/bl;;j++){
      if(j * bl > r) break;
      if(j * bl >= l) t=j;
    }
    pp = l;
    li = l;
    if(t != -1){
      pp = dp[l][t];
      li = t * bl+1;
    }
    while(li <= r){
      if(pi[li] >= l && pi[li] <= pp) pp=li;
      li++;
    }
    cout << pp << "\n";
  }
  return 0;
}