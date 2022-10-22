#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

using perm_t = vector<uint8_t>;

int calc_rev(bitset<20> bs, const perm_t& perm) {
  bitset<20> res;
  REP(i,(int)size(perm)) {
    res.set(perm[i], bs.test(i));
  }
  return res.to_ulong();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m,k;
  cin>>n>>m>>k;
  string ss,st;
  cin>>ss>>st;
  bitset<20> s,t;
  REP(i,k) {
    s[i] = ss[i] == '1';
    t[i] = st[i] == '1';
  }
  perm_t perm(k);
  iota(ALL(perm), 0);
  vecint from_s(n+1);
  from_s[0] = s.to_ulong();
  vecint from_t(n);
  vector<tuple<int,int>> vs;
  REP(i,n) {
    int a,b;
    cin>>a>>b;
    --a;--b;
    vs.emplace_back(a,b);
    swap(perm[a], perm[b]);
    from_t[i] = calc_rev(t, perm);
    from_s[i+1] = calc_rev(s, perm);
  }
  const int INF = 1e8;
  vecint dist(1<<k, INF);
  vecint l(1<<k, INF);
  ll mnd = INF;
  int mnl = 0;
  int mnr = 0;
  REP(i,n) {
    if (i >= m-1) {
      int idx = i - m + 1;
      int bits = from_s[idx];
      dist[bits] = 0;
      l[bits] = idx;
      queue<int> q;
      q.push(bits);
      while (!q.empty()) {
        int j = q.front();
        q.pop();
        REP(bit,k) {
          int nx = j ^ (1 << bit);
          if (dist[nx] > dist[j] + 1) {
            dist[nx] = dist[j] + 1;
            l[nx] = idx;
            q.push(nx);
          }
        }
      }
    }
    int bits = from_t[i];
    if (dist[bits] < mnd) {
      mnd = dist[bits];
      mnl = l[bits];
      mnr = i+1;
    }
  }
  cout<<k-mnd<<"\n";
  cout<<(mnl+1)<<" "<<mnr<<endl;
  return 0;
}