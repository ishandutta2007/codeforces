#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  int n;
  cin>>n;
  vector<ll> a(n);
  REP(i,n) cin>>a[i];
  vector<vecint> g(n);
  bool c3 = false;
  set<int> v;
  vector<tuple<int,int>> ve;
  REP(i,60) {
    vector<int> s;
    REP(j,n) {
      if((a[j]>>i)&1) s.push_back(j);
    }
    if (s.size() >= 3) {
      c3 = true;
      break;
    } else if (s.size() == 2) {
      int p = s[0];
      int q = s[1];
      g[p].push_back(q);
      g[q].push_back(p);
      v.insert(p);
      v.insert(q);
      ve.emplace_back(p, q);
    }
  }
  if (c3) {
    cout<<3<<endl;
    return 0;
  }
  int mn = n+1;
  for (int s : v) {
    queue<tuple<int,int>> q;
    map<int,int> dist;
    map<int,int> parent;
    q.emplace(s, 1);
    dist[s] = 0;
    while (!q.empty()) {
      int idx, d;
      tie(idx, d) = q.front();
      q.pop();
      for (int nx : g[idx]) {
        if (!dist.count(nx)) {
          dist[nx] = d+1;
          parent[nx] = idx;
          q.emplace(nx, d+1);
        }
      }
    }
    for (auto t : ve) {
      int p, q;
      tie(p, q) = t;
      set<int> pp, pq;
      int ap = p;
      int aq = q;
      while (parent.count(ap)) {
        pp.insert(ap);
        ap = parent[ap];
      }
      if (pp.empty()) continue;
      while (parent.count(aq)) {
        pq.insert(aq);
        aq = parent[aq];
      }
      if (pq.empty()) continue;
      vecint ins;
      set_intersection(begin(pp),end(pp),begin(pq),end(pq),back_inserter(ins));
      if (ins.size() == 0 && pp.count(q) == 0 && pq.count(p) == 0) {
        mn = min(mn, (int)(pp.size() + pq.size() + 1));
      }
    }
  }
  if (mn <= n) {
    cout << mn << endl;
  } else {
    cout<< -1 << endl;
  }
  return 0;
}