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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<int> a(n),b(n);
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>b[i];
  vector<ll> c(n);
  rep(i,n) c[i]=a[i]+b[i];
  ll sum=accumulate(all(c),0ll);
  int ok=1;
  if(sum%(2*n)) ok=0;
  sum/=2*n;
  vector<int> re(n);
  rep(i,n){
    c[i]-=sum;
    if(c[i]<0 || c[i]%n) ok=0;
    re[i]=c[i]/n;
  }
  vector<ll> cnt(30);
  for(int x:re) rep(j,30) if(x>>j&1) ++cnt[j];
  rep(i,n){
    ll x=0,y=0;
    rep(j,30)
      if(re[i]>>j&1){
	x+=cnt[j]<<j;
	y+=ll(n)<<j;
      }else{
	y+=cnt[j]<<j;
      }
    if(x!=a[i] || y!=b[i]) ok=0;
  }
  if(ok){
    for(int x:re) cout<<x<<" ";cout<<endl;
  }else{
    cout<<-1<<endl;
  }
  return 0;
}