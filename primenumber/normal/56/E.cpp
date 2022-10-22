#include <bits/stdc++.h>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int n;
  cin>>n;
  vector<tuple<int,int,int>> vx;
  REP(i,n) {
    int x,h;
    cin>>x>>h;
    vx.emplace_back(x,h,i);
  }
  sort(begin(vx),end(vx),greater<tuple<int,int,int>>());
  using P = tuple<int,int>;
  priority_queue<P,vector<P>,greater<P>> q;
  vector<int> res(n);
  for(auto p:vx) {
    int x,h,i;
    tie(x,h,i) = p;
    int sum = 1;
    while(!q.empty() &&get<0>(q.top()) < x+h) {
      int xi,s;
      tie(xi,s) = q.top();
      sum += s;
      q.pop();
    }
    res[i] = sum;
    q.push(make_tuple(x,sum));
  }
  REP(i,n){
    if(i)cout<<' ';
    cout<<res[i];
  }
  cout<<endl;
  return 0;
}