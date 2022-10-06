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
#include<unordered_set>
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
const ll INF=1e11;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  ll n,m,t,x,s;
  cin>>n>>m>>t>>x>>s;
  vector<pll> a(m+1),b(t+1);
  rep(i,m) cin>>a[i+1].Y;
  rep(i,m) cin>>a[i+1].X;
  rep(i,t) cin>>b[i+1].Y;
  rep(i,t) cin>>b[i+1].X;
  a[0].Y=x;
  ll re=n*x;
  for(pll p:a){
    if(p.X>s) continue;
    auto it=upper_bound(all(b),pll(s-p.X,INF)); --it;
    ll rem=max(0ll,n-it->Y);
    MN(re,rem*p.Y);
    //cout<<p<<rem/p.Y<<*it<<endl;
  }
  cout<<re<<endl;
  return 0;
}