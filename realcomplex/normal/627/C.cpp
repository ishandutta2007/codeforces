#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const ll MAXN = 1234567;

ll tree[MAXN * 2];

void upd(ll cost, ll pos){
  cost += MAXN;
  tree[cost] = min(tree[cost], pos);
  cost /= 2;
  while(cost > 0){
    tree[cost] = min(tree[cost * 2], tree[cost * 2 + 1]);
    cost /= 2;
  }
}

ll query(ll L, ll R){
  L += MAXN;
  R += MAXN;
  ll ans = (ll)1e9 + 9;
  while(L <= R){
    if(L % 2 == 1){
      ans = min(ans, tree[L]);
      L ++ ;
    }
    if(R % 2 == 0){
      ans = min(ans, tree[R]);
      R -- ;
    }
    L /= 2;
    R /= 2;
  }
  return ans;
}

void setto(){
  memset(tree, (ll)2e9 + 9, sizeof tree);
}

const ll N = (ll)2e5 + 9;
ll travel[N];

int main(){
  ll d,n,m;
  cin >> d >> n >> m;
  setto();
  pii cur;
  vector<pii> cc;
  for(ll i = 0;i < m;i ++ ){
    cin >> cur.fi >> cur.se;
    cc.push_back(cur);
  }
  cc.push_back(mp(d, 0));
  cc.push_back(mp(0, 0));
  sort(cc.begin(), cc.end());
  upd(0, d);
  ll nex_pos;
  for(ll i = 1;i < cc.size(); i ++ ){
    if(cc[i].fi - cc[i - 1].fi > n){
      cout << -1;
      return 0;
    }
  }
  for(ll i = cc.size() - 2; i >= 0; i -- ){
    nex_pos = query(0, cc[i].se);
    travel[i] = nex_pos - cc[i].fi; 
    upd(cc[i].se, cc[i].fi);
  } 
  ll gas = 0;
  ll req;
  ll ans = 0;
  ll add;
  ll ct;
  for(ll i = 0;i < cc.size() - 1;i ++ ){
    req = min(travel[i], n);
    if(gas >= req){
      gas -= cc[i + 1].fi - cc[i].fi;
      continue;
    }
    add = req - gas;
    ct = cc[i].se;
    ans += 1ll * add * ct;
    gas = req;
    gas -= cc[i + 1].fi - cc[i].fi;
  }
  cout << ans;
  return 0;
}