#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const int M = (int)2 * N + 512;

pii bes[M][2];
int cnt[N];
void solve(){
  int n;
  cin >> n;
  for(int i = 0 ; i <= 2 * n; i ++ )
    bes[i][0]=bes[i][1] = mp(-(int)1e9 - 10, -1);
  for(int i = 0 ; i < n + 2 ; i ++ )
    cnt[i] = 0;
  vector<pii> f;
  int l, r;
  vector<int> compr;
  for(int i = 0 ; i < n; i ++ ){
    cin >> l >> r;
    f.push_back(mp(l,r));
    compr.push_back(l);
    compr.push_back(r);
  }
  compr.push_back(-(int)1e9 - 10);
  sort(compr.begin(), compr.end());
  compr.resize(unique(compr.begin(), compr.end()) - compr.begin());
  for(auto &x : f){
    x.fi = lower_bound(compr.begin(), compr.end(), x.fi) - compr.begin();
    x.se = lower_bound(compr.begin(), compr.end(), x.se) - compr.begin();
  }
  int m = compr.size();
  pii pp;
  int id = 0;
  for(auto x : f){
    pp = mp(x.se, id);
    if(pp > bes[x.fi][0]){
      bes[x.fi][1] = bes[x.fi][0];
      bes[x.fi][0] = pp;
    }
    else if(pp > bes[x.fi][1]){
      bes[x.fi][1] = pp; 
    }
    id ++ ;
  }
  for(int i = 1; i < m ; i ++ ){
    vector<pii> t;
    for(int j = 0 ; j < 2; j ++ ){
      t.push_back(bes[i][j]);
      t.push_back(bes[i-1][j]);
    }
    sort(t.begin(), t.end());
    for(int j = 3; j >= 2; j -- ){
      bes[i][4-j-1] = t[j];
    }
  }
  for(int i = 0 ; i < m; i ++ ){
    if(bes[i][0].fi == i && bes[i][1].fi == i){
      cnt[0]++;
    }
    else if(bes[i][0].fi == i){
      cnt[0]++;
      cnt[bes[i][0].se]--;
      cnt[bes[i][0].se+1]++;
    }
    else if(bes[i][1].fi == i){
      cnt[bes[i][0].se] ++ ;
      cnt[bes[i][0].se+1]--;
    }
  }
  int res = 0;
  for(int i = 1; i < n ; i ++ )
    cnt[i] += cnt[i - 1];
  for(int i = 0 ; i < n; i ++ )
    res = max(res, cnt[i]);
  cout << res << "\n";
}

int main(){
  fastIO;
  int testc;
  cin >> testc;
  for(int t = 0 ;t < testc; t ++ ){
    solve();
  }
  return 0;
}