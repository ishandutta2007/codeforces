#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

using Data = ll;

struct StarrySky {
  static const int MAX_DEPTH = 21;
  static const int STsize = 1 << MAX_DEPTH;
  vector<Data> data;
  vector<Data> lazy; int n;
  StarrySky(void) : data(STsize, 0), lazy(STsize, 0), n(STsize / 2) {
  }
  void add(int fr, int to, Data val) { upd_sub(fr, to, 2*n-2, 0, n, val); }
  Data maximum(int fr, int to) { return max_sub(fr, to, 2*n-2, 0, n); }
private:
  void upd_sub(int fr, int to, int node, int la, int ra, Data val) {
    if (ra<=fr || to<=la) return;
    if (fr<=la && ra<=to) { lazy[node] += val; return; }
    int left = (node - n) * 2, right = left + 1;
    upd_sub(fr, to, left, la, (la+ra)/2, val);
    upd_sub(fr, to, right, (la+ra)/2, ra, val);
    data[node] = max(data[left] + lazy[left], data[right] + lazy[right]);
  }
  Data max_sub(int fr, int to, int node, int la, int ra) {
    if (ra<=fr || to<=la) return 0x8000000000000000l;
    if (fr<=la && ra<=to) return data[node] + lazy[node];
    Data vl = max_sub(fr, to, (node-n)*2+0, la, (la+ra)/2);
    Data vr = max_sub(fr, to, (node-n)*2+1, (la+ra)/2, ra);
    return lazy[node] + max(vl, vr);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,p;
  cin>>n>>m>>p;
  constexpr ll INF = 1e18;
  vecll needa(1000001, INF);
  vector<pair<ll,ll>> va;
  REP(i,n) {
    ll a,c;
    cin>>a>>c;
    va.emplace_back(a,c);
    needa[a] = min(needa[a], c);
  }
  for(int i=1000000;i>0;--i) {
    needa[i-1] = min(needa[i-1], needa[i]);
  }
  needa[0] = 0;
  sort(ALL(va));
  reverse(ALL(va));
  vecll needb(1000001, INF);
  vector<pair<ll,ll>> vb;
  REP(i,m) {
    ll b,c;
    cin>>b>>c;
    vb.emplace_back(b,c);
    needb[b] = min(needb[b], c);
  }
  sort(ALL(vb));
  reverse(ALL(vb));
  for(int i=1000000;i>0;--i) {
    needb[i-1] = min(needb[i-1], needb[i]);
  }
  StarrySky ss;
  REP(i,1000000) {
    int idx = i+1;
    ss.add(idx,idx+1,-needb[idx]);
  }
  vector<tuple<ll,ll,ll>> vt;
  REP(i,p) {
    ll x,y,z;
    cin>>x>>y>>z;
    vt.emplace_back(x,y,z);
    ss.add(y+1,1000001,z);
  }
  sort(ALL(vt));
  reverse(ALL(vt));
  auto itr = begin(vt);
  ll ans = -INF;
  REP(i,1000000) {
    int cur = 1000000 - i;
    while (itr != end(vt)) {
      ll x,y,z;
      tie(x,y,z) = *itr;
      if (x < cur) break;
      ++itr;
      ss.add(y+1,1000001,-z);
    }
    ll tmp = -needa[cur] + ss.maximum(1,1000001);
    ans = max(ans, tmp);
  }
  cout<<ans<<endl;
  return 0;
}