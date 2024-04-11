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
  int n;
  cin>>n;
  vector<vecint> g(n);
  REP(i,n-1) {
    int x,y;
    cin>>x>>y;
    --x;--y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  auto query = [](int x,int y) {
    cout<<"? "<<x+1<<" "<<y+1<<endl;
    int res;
    cin>>res;
    return res-1;
  };
  queue<int> q;
  REP(i,n) {
    if (size(g[i]) == 1) q.push(i);
  }
  while (q.size() >= 2) {
    int i = q.front(); q.pop();
    int j = q.front(); q.pop();
    int lca = query(i,j);
    if (lca == i) {
      cout<<"! "<<i+1<<endl;
      return 0;
    }
    if (lca == j) {
      cout<<"! "<<j+1<<endl;
      return 0;
    }
    auto to = g[i][0];
    g[to].erase(remove(ALL(g[to]),i),end(g[to]));
    if (size(g[to]) == 1) q.push(to);
    auto to2 = g[j][0];
    g[to2].erase(remove(ALL(g[to2]),j),end(g[to2]));
    if (size(g[to2]) == 1) q.push(to2);
  }
  cout<<"! "<<q.front()+1<<endl;
  return 0;
}