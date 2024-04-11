#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

int lim;
pii tree[N * 2 + 512];

void upd(int p, pii v){ 
  p += lim;
  tree[p].fi += v.fi;
  tree[p].se += v.se;
  p /= 2;
  while(p > 0){
    tree[p].fi = tree[p * 2].fi + tree[p * 2 + 1].fi;
    tree[p].se = tree[p * 2].se + tree[p * 2 + 1].se;
    p /= 2;
  }
}

pii ask(int l, int r){
  l += lim;
  r += lim;
  pii res = {0,0};
  while(l <= r){
    if(l % 2 == 1){
      res.fi += tree[l].fi;
      res.se += tree[l].se;
      l ++ ;
    }
    if(r % 2 == 0){
      res.fi += tree[r].fi;
      res.se += tree[r].se;
      r -- ;
    }
    l /= 2;
    r /= 2;
  }
  return res;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  lim = n + 5;
  vector<pii> t(n);
  for(int i = 0 ; i < n ; i ++ ){
    cin >> t[i].fi;
  }
  vector<int> cmp;
  for(int i = 0 ;i < n; i ++ ){
    cin >> t[i].se;
    cmp.push_back(t[i].se);
  }
  sort(t.begin(), t.end());
  cmp.push_back(0);
  cmp.push_back(-(int)1e9);
  cmp.push_back(+(int)1e9);
  sort(cmp.begin(), cmp.end());
  cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
  for(int i = 0 ;i  < n ; i ++ ){
    t[i].se = lower_bound(cmp.begin(), cmp.end(), t[i].se) - cmp.begin();
    upd(t[i].se, mp(t[i].fi,+1));
  }
  ll res = 0;
  pii qq;
  for(int i = 0 ;i < n ; i ++ ){
    upd(t[i].se, mp(-t[i].fi,-1));
    qq = ask(t[i].se, lim - 1);
    res += qq.fi - qq.se * 1ll * t[i].fi;
  }
  cout << res << "\n";
  return 0;
}