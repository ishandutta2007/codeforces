#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

typedef pair<pii,int> piii;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  vector<int> a(n),b(m);
  rep(i,n) cin>>a[i];
  rep(i,m) cin>>b[i];
  priority_queue<piii> que;
  rep(i,m) que.emplace(pii(b[i],0),i);
  vector<pii> ps(n);
  rep(i,n) ps[i]=pii(a[i],i);
  sort(rall(ps));
  vector<int> re(n),cost(m);
  int cnt=0;
  for(pii p:ps){
    while(que.size() && que.top().X.X>p.X){
      auto tmp=que.top(); que.pop();
      tmp.X.X=(tmp.X.X+1)/2;
      --tmp.X.Y;
      que.push(tmp);
    }
    //cout<<p<<que.top()<<endl;
    if(que.size() && que.top().X.X==p.X){
      re[p.Y]=que.top().Y+1;
      cost[que.top().Y]=-que.top().X.Y;
      que.pop();
      ++cnt;
    }
  }
  cout<<cnt<<" "<<accumulate(all(cost),0)<<endl;
  for(int x:cost) cout<<x<<" ";cout<<endl;
  for(int x:re) cout<<x<<" ";cout<<endl;
  return 0;
}