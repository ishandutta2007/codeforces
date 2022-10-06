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
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
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
const ll INF=1e10;
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  ll n,t;
  cin>>n>>t;
  ++n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  reverse(all(a));
  vector<ll> l=a;
  rep(i,n)if(i){
    l[i]+=l[i-1]*2;
    l[i]=max(min(l[i],INF),-INF);
  }
  ll ans=0,re=0;
  //cout<<a<<l;
  rrep(i,n){
    const ll ret=a[i]+ans-l[i];
    //cout<<ans<<":"<<a[i]<<"->"<<ret<<endl;
    if(abs(ret)<=t) ++re;
    if(ret==0 && i==0) --re;
    ans-=a[i];
    if(ans%2) break;
    ans/=2;
  }
  cout<<re<<endl;
  return 0;
}