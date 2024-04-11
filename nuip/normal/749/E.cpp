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
#define Endl endl

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
const int nn=112345;
ll bit[nn+1];

ll Sum(int i){ ++i;
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i,ll x){ ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i], --a[i];
  double re=0,ret=0;
  ll s=0;
  rep(j,n){
    ll lt=Sum(a[j]);
    //cout<<j<<pii(lt,s-lt)<<endl;
    re+=(lt-(s-lt))*(n-j);
    add(a[j],j+1);
    s+=j+1;
    rep(i,j){
      if(a[i]<a[j]) ret+=(i+1)*(n-j);
      if(a[i]>a[j]) ret-=(i+1)*(n-j);
    }
    //cout<<re<<endl<<ret<<endl<<endl;
  }
  ll inv=0;
  fill(bit,bit+nn+1,0);
  rep(j,n){
    inv+=j-Sum(a[j]);
    add(a[j],1);
  }
  cout<<inv+re/n/(n+1)<<endl;
  return 0;
}