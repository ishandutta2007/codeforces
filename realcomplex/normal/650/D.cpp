#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 9;

int a[N];
int lf[N];
int rf[N];
int no[N];
vector<pii> F[N];
int res1[N];
int iq[N];
int vv[N];

void solve(int l, int r){
  if(l >= r) return;
  int mid = (l + r) / 2;
  vector<pii> tt;
  for(int i = r ; i > mid ; i -- ){
    tt.push_back(mp(a[i], rf[i]));
  }
  tt.push_back(mp((int)1e9 + 579, 0));
  sort(tt.begin(), tt.end());
  for(int i = (int)tt.size() - 2; i >= 0 ; i -- ){
    tt[i].se = max(tt[i].se, tt[i + 1].se);
  }
  int res = tt[0].se;
  int id;
  for(int i = l ; i <= mid; i ++ ){
    no[i] = max(no[i],res);
    id = upper_bound(tt.begin(), tt.end(), mp(a[i]+1,-1)) - tt.begin();
    res = max(res, lf[i] + tt[id].se);
  }

  tt.clear();
  for(int i = l ; i <= mid ; i ++ ){
    tt.push_back(mp(a[i], lf[i]));
  }
  tt.push_back(mp(0,0));
  sort(tt.begin(), tt.end());
  for(int i = 1; i < tt.size(); i ++ )
    tt[i].se = max(tt[i].se, tt[i-1].se);
  int li, ri, mi;
  res = tt[(int)tt.size() - 1].se;
  for(int i = r; i > mid; i -- ){
    no[i] = max(no[i],res);
    li = 0, ri = tt.size();
    while(li + 1 < ri){
      mi = (li + ri) / 2;
      if(tt[mi].fi < a[i])
        li = mi;
      else
        ri = mi;
    }
    res = max(res, rf[i] + tt[li].se);
  }
  solve(l, mid);
  solve(mid + 1, r);
}

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i ++ )
    cin >> a[i];
  for(int i = 1; i <= q; i ++ ){
    cin >> iq[i] >> vv[i];
    res1[i] = 1;
    F[iq[i]].push_back(mp(vv[i], i));
  }
  vector<int> cur;
  cur.push_back(0);
  int x;
  int id;
  for(int i = 1; i <= n; i ++ ){
    for(auto p : F[i]){
      id = lower_bound(cur.begin(), cur.end(), p.fi) - cur.begin();
      id -- ;
      res1[p.se] += id;
    }
    x = lower_bound(cur.begin(), cur.end(), a[i]) - cur.begin();
    if(x == cur.size())
      cur.push_back(a[i]);
    else
      cur[x] = min(cur[x], a[i]);
    lf[i] = x;
  }
  cur.clear();
  cur.push_back((int)2e9 + 11);
  int li, ri, md;
  for(int i = n; i >= 1; i -- ){
    for(auto p : F[i]){
      li = 0, ri = (int)cur.size();
      while(li < ri){
        md = (li + ri) / 2;
        if(cur[md] > p.fi)
          li = md + 1;
        else
          ri = md;
      }
      res1[p.se] += li-1;
    }
    li = 0, ri = (int)cur.size();
    while(li < ri){
      md = (li + ri) / 2;
      if(cur[md] > a[i])
        li = md + 1;
      else
        ri = md;
    }
    if(li == (int)cur.size())
      cur.push_back(a[i]);
    else
      cur[li] = max(cur[li], a[i]);
    rf[i] = li;
  }
  solve(1, n);
  for(int i = 1; i <= q; i ++ ){
    cout << max(res1[i], no[iq[i]]) << "\n";
  }
  return 0;
}