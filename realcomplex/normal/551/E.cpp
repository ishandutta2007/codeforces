#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)5e5 + 91;

signed main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  int block = int(sqrt(n));
  int tot = (n + block - 1)/block;
  vector<pii> cur;
  vector<pii> al[tot];
  int add_sum[tot];
  for(int i = 0;i < tot;i ++ )
    add_sum[i] = 0ll;
  int a[n];
  for(int i = 0 ;i < n; i++ ){
    cin >> a[i];
    cur.push_back(mp(a[i], i));
    if(i + 1 == n or (i+1)%block == 0){
      sort(cur.begin(), cur.end());
      al[i/block] = cur;
      cur.clear();
    }
  }
  int t;
  int l, r, x;
  int check;
  int xl, xr;
  int tl, tr;
  int y;
  int ix;
  int mi, mj;
  for(int i = 0;i < q;i ++ ){
    cin >> t;
    if(t == 1){
      cin >> l >> r >> x;
      --l;
      --r;
      vector<int> bf, af;
      xl = -1, xr = -1;
      while(l % block != 0 and l <= r){
        bf.push_back(l);
        xl = l/block;
        l ++ ;
      }
      while(l + block - 1 <= r){
        add_sum[l / block] += x;
        l += block;
      }
      while(l <= r){
        af.push_back(l);
        xr = l/block;
        l ++ ;
      }
      for(auto y : bf) a[y] += x;
      for(auto y : af) a[y] += x;
      if(xr != -1){
        tl = xr * block;
        tr = tl + block - 1;
        tr = min(tr, n-1);
        cur.clear();
        for(int j = tl; j <= tr; j ++ ){
          cur.push_back(mp(a[j], j));
        } 
        sort(cur.begin(), cur.end());
        al[xr].clear();
        al[xr] = cur;
      }
      if(xl != -1){
        tl = xl * block;
        tr = tl + block - 1;
        tr = min(tr, n - 1);
        cur.clear();
        for(int j = tl; j <= tr;j ++ ){
          cur.push_back(mp(a[j], j));
        }
        sort(cur.begin(), cur.end());
        al[xl].clear();
        al[xl] = cur;
      }
    }
    else{
      cin >> y;
      mi = 0;
      mj = n;
      for(int j = 0; j < tot; j++ ){
        check = y - add_sum[j];
        ix = lower_bound(al[j].begin(), al[j].end(), mp(check, -1ll)) - al[j].begin();
        if(ix < al[j].size() and al[j][ix].fi == check)mj = min(mj, al[j][ix].se);
        ix = lower_bound(al[j].begin(), al[j].end(), mp(check + 1, -1ll)) - al[j].begin();
        ix -- ;
        if(ix >= 0 and al[j][ix].fi == check) mi = max(mi, al[j][ix].se);
      }
      if(mj >= n)
        cout << -1 << "\n";
      else
        cout << mi - mj << "\n";
    }
  }
  return 0;
}