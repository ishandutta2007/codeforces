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

const ll MAX_N = 1005;
ll hy[MAX_N][MAX_N];
bool has[MAX_N][MAX_N];

pii nex[MAX_N][MAX_N];
ll siz[MAX_N][MAX_N];

pii fin(pii jj){
  if(nex[jj.fi][jj.se] == jj)
    return jj;
  nex[jj.fi][jj.se] = fin(nex[jj.fi][jj.se]);
  return nex[jj.fi][jj.se];
}

void unite(pii ii, pii jj){
  ii = fin(ii);
  jj = fin(jj);
  if(ii == jj)
    return;
  if(siz[ii.fi][ii.se] > siz[jj.fi][jj.se])
    swap(ii, jj);
  siz[jj.fi][jj.se] += siz[ii.fi][ii.se];
  nex[ii.fi][ii.se] = jj;
}

ll n,m;
bool incl[MAX_N][MAX_N];

void toAns(pii start, ll locations, ll tt){
  queue<pii> pp;
  pp.push(start);
  while(!pp.empty()){
    locations -- ;
    start = pp.front();
    has[start.fi][start.se] = false;
    hy[start.fi][start.se] = tt;
    incl[start.fi][start.se] = true;
    pp.pop();
    if(locations == 0)
      break;
    if(has[start.fi][start.se + 1]){
      has[start.fi][start.se + 1] = false;
      pp.push(mp(start.fi, start.se + 1));
    }
    if(has[start.fi][start.se - 1]){
      has[start.fi][start.se - 1] = false;
      pp.push(mp(start.fi, start.se - 1));
    }
    if(has[start.fi + 1][start.se]){
      has[start.fi + 1][start.se] = false;
      pp.push(mp(start.fi + 1, start.se));
    }
    if(has[start.fi - 1][start.se]){
      has[start.fi - 1][start.se] = false;
      pp.push(mp(start.fi - 1, start.se));
    }
  }
  cout << "YES\n";
  for(ll i = 1;i <= n; i ++ ){
    for(ll j = 1;j <= m;j ++ ){
      cout << (incl[i][j] == true ? hy[i][j] : 0) << " ";
    }
    cout << "\n";
  }
  exit(0);
}

int main(){
  fastIO;
  ll k;
  cin >> n >> m >> k;
  vector<pair<ll, pii>> hyy;
  for(ll i = 1;i <= n; i++ ){
    for(ll j = 1;j <= m;j ++ ){
      cin >> hy[i][j];
      nex[i][j].fi = i;
      nex[i][j].se = j;
      siz[i][j] = 1;
      hyy.push_back(mp(hy[i][j], mp(i, j)));
    }
  }
  sort(hyy.begin(), hyy.end());
  reverse(hyy.begin(), hyy.end());
  ll amount;
  pii pos;
  ll req_uni;
  pii center;
  for(auto H : hyy){
    amount = H.fi;
    pos = H.se;
    has[pos.fi][pos.se] = true;
    if(has[pos.fi][pos.se + 1] == true)
      unite(pos, mp(pos.fi, pos.se + 1));
    if(has[pos.fi][pos.se - 1] == true)
      unite(pos, mp(pos.fi, pos.se - 1));
    if(has[pos.fi + 1][pos.se] == true)
      unite(pos, mp(pos.fi + 1, pos.se));
    if(has[pos.fi - 1][pos.se] == true)
      unite(pos, mp(pos.fi - 1, pos.se));
    if(k % amount != 0)
      continue;
    req_uni = k / amount;
    center = fin(pos);
    if(siz[center.fi][center.se] < req_uni)
      continue;
    toAns(pos, req_uni, amount);
  }
  cout << "NO\n";
  return 0;
}