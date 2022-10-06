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

int n,p,q;
vector<int> a,b;

double fun(double x){
  double y=1;
  rep(i,n)
    y=min(y,(1-a[i]*x)/b[i]);
  if(y<0) return -1;
  return p*x+q*y;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  cin>>n>>p>>q;
  a.resize(n);
  b.resize(n);
  rep(i,n) cin>>a[i]>>b[i];
  
  double l=0,r=1./(*max_element(all(a))),m1,m2;
  rep(hoge,700){
    //cout<<l<<","<<r<<endl;
    m1=(l*2+r)/3;
    m2=(l+r*2)/3;
    //cout<<fun(m1)<<","<<fun(m2)<<endl;
    if(fun(m1)>fun(m2)){
      r=m2;
    }else{
      l=m1;
    }
  }
  cout<<fun(m1)<<endl;
  return 0;
}