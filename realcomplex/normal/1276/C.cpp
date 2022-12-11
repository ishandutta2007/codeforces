#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

map<int, int> cnt;
const int N = (int)5e5 + 9;
int chk[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<pii> t;
  int a;
  for(int i = 1; i <= n; i ++ ){
    cin >> a;
    cnt[a] ++ ;
  }
  for(auto x : cnt){
    t.push_back(mp(x.se, x.fi));
  }
  sort(t.begin(), t.end());
  chk[n] = n;
  int p=(int)t.size()-1;
  for(int i = n-1; i >= 1; i -- ){
    chk[i] = chk[i + 1]-((int)t.size()-p-1);
    while(p >= 0 && t[p].fi == i + 1){
      chk[i]--;
      p--;
    }
  }
  int sz;
  int bp = 1, bq = 1, ans = 0;
  for(int q = n; q >= 1; q -- ){
    p = 0;
    sz = 0;
    while(1){
      if(sz + q > n || p + 1 > q) break;
      if(chk[p + 1] < sz + q) break;
      sz += q;
      p ++ ;
    }
    if(sz >= ans){
      ans = sz;
      bp = p;
      bq = q;
    }
  }
  cout << ans << "\n";
  cout << bp << " " << bq << "\n";
  int res[bp][bq];
  int ci, cj;
  vector<pii> ord;
  int k = 0;
  for(int i = 0 ; i < bq; i ++ ){
    ci=0;
    cj=i;
    for(int j = 0 ; j < bp; j ++ ){
      ord.push_back(mp(ci,cj));
      ci++;
      cj=(cj+1)%bq;
    }
  }
  int c = ans;
  int f;
  p = 0;
  for(int i = t.size() - 1 ; i >= 0; i -- ){
    t[i].fi = min(t[i].fi,bp);
    f = min(c, t[i].fi);
    for(int j = 0 ; j < f; j ++ ){
      res[ord[p].fi][ord[p].se] = t[i].se;
      p ++ ;
    }
    c -= f;
  }
  for(int i = 0 ; i < bp ; i ++ ){
    for(int j = 0 ; j < bq; j ++ ){
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}