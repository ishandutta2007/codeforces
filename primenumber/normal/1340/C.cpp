#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vecint d(m);
  REP(i,m) cin>>d[i];
  sort(ALL(d));
  int g,r;
  cin>>g>>r;
  int k = m*g;
  deque<int> q;
  q.push_back(0);
  vector<int> dis(k, 1000000000);
  dis[0] = 0;
  while (!q.empty()) {
    int i = q.front();
    q.pop_front();
    int x = i / g;
    int y = i % g;
    int c = y ? 0 : 1;
    if (x < m-1) {
      int d1 = d[x+1] - d[x];
      if (y + d1 <= g) {
        int j = (x+1)*g+(y+d1)%g;
        if (dis[j] > dis[i] + c) {
          dis[j] = dis[i] + c;
          if (c) q.push_back(j);
          else q.push_front(j);
        }
      }
    }
    if (x > 0) {
      int d1 = d[x] - d[x-1];
      if (y + d1 <= g) {
        int j = (x-1)*g+(y+d1)%g;
        if (dis[j] > dis[i] + c) {
          dis[j] = dis[i] + c;
          if (c) q.push_back(j);
          else q.push_front(j);
        }
      }
    }
  }
  ll mn = 1000000000;
  REP(i,g) {
    if (i) {
      mn = min(mn, ll(g+r)*(dis[g*(m-1)+i]-1) + i);
    } else {
      mn = min(mn, ll(g+r)*(dis[g*(m-1)+i]-1) + g);
    }
  }
  if (mn == 1000000000) {
    cout<<-1<<endl;
  }else {
    cout<<mn<<endl;
  }
  return 0;
}