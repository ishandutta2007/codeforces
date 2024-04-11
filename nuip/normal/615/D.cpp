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
const ll MOD=1e9+7;

ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=MOD-1)+=MOD-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  map<int,int> ps;
  int p;
  rep(i,n){
    cin>>p;
    ++ps[p];
  }
  vector<pii> vs(all(ps));
  int m=vs.size();
  vector<ll> prodl(m+1,1),prodr(m+1,1);
  rep(i,m) prodl[i+1]=prodl[i]*(vs[i].Y+1)%(MOD-1);
  rrep(i,m) prodr[i]=prodr[i+1]*(vs[i].Y+1)%(MOD-1);

  ll re=1,tmp;
  rep(i,m){
    pii p=vs[i];
    (re*=modpow(p.X,prodl[i]%(MOD-1)*prodr[i+1]%(MOD-1)
		*((p.Y+1ll)*p.Y/2%(MOD-1))%(MOD-1)))%=MOD;
  }
  cout<<re<<endl;
  return 0;
}