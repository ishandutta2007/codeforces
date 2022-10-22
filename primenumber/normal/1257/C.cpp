#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  int t;
  cin>>t;
  REP(cases,t) {
    int n;
    cin>>n;
    constexpr int INF = 1e9;
    vecint prev(n+1, -INF);
    int shortest = INF;
    REP(i,n) {
      int a;
      cin>>a;
      shortest = min(shortest, i - prev[a] + 1);
      prev[a] = i;
    }
    if (shortest < INF) {
      cout<<shortest<<endl;
    } else {
      cout<<-1<<endl;
    }
  }
  return 0;
}