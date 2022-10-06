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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  vector<ll> c(n);
  rep(i,n) cin>>c[i];
  ll s=accumulate(all(c),0ll);
  rep(i,2) rep(j,n) c.pb(c[j]);
  vector<int> d(m);
  rep(i,m) cin>>d[i],--d[i];
  ll re=0;
  rep(i,n) re+=c[i]*c[i+1];
  for(int i:d) re+=c[i]*(s-c[i]-c[i+1]-c[i+n-1]);
  ll sum=0;
  for(int i:d) sum+=c[i];
  sum*=sum;
  for(int i:d) sum-=c[i]*c[i];
  sum/=2;
  vector<int> cap(2*n);
  for(int i:d) cap[i]=cap[i+n]=1;
  rep(i,n) if(cap[i]&&cap[i+1]) sum-=c[i]*c[i+1];
  re-=sum;
  cout<<re<<endl;
  return 0;
}