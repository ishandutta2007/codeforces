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

const int nn=312345;
ll bit[nn+1];
ll cnt[nn+1];
const ll INF=ll(1e18)+100;

ll sum(int i,ll *bit=bit){ ++i;
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
    if(s>INF) return INF;
  }
  return s;
}

void add(int i,ll x,ll *bit=bit){ ++i;
  while(i<=nn){
    MN(bit[i]+=x,INF);
    i+=i&-i;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  ll m,unko;
  cin>>m>>unko; --n;
  vector<pll> ps(n);
  rep(i,n) cin>>ps[i].X>>ps[i].Y;
  vector<pll> zip(n);
  rep(i,n) zip[i]=pll(ps[i].Y-ps[i].X+1,i);
  sort(all(zip));
  vector<pll> qs(n);
  vector<int> inv(n);
  rep(i,n) qs[i]=pll(ps[i].X,i);
  rep(i,n) inv[zip[i].Y]=i;
  qs.eb(0,-1);
  sort(rall(qs));
  //cout<<m<<ps<<qs<<zip<<inv;
  ll re=n;
  rep(i,qs.size()){
    pll p=qs[i];
    //cout<<p<<":"<<sum(1)<<endl;
    ll b=p.X;
    int l=0,r=302345;
    while(r-l>1){
      const int med=(l+r)/2;
      if(sum(med)+b<=m) l=med;
      else r=med;
    }
    if(b<=m && (i==0 || qs[i-1].X!=p.X)){
      MN(re,sum(302345,cnt)-sum(l,cnt));
      //cout<<l<<":"<<pll(sum(302345,cnt),sum(l,cnt))<<endl;
    }
    if(p.Y<0) continue;
    //cout<<pll(inv[p.Y],zip[inv[p.Y]].X)<<endl;
    add(inv[p.Y]+1,zip[inv[p.Y]].X);
    add(inv[p.Y]+1,1,cnt);
  }
  cout<<re+1<<endl;
  return 0;
}