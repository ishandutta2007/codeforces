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

int swp;
int ask(int x,int y,int X,int Y){
  if(x>=X || y>=Y) return 0;
  ++x; ++y;
  if(swp){
    cout<<"? "<<y<<" "<<x<<" "<<Y<<" "<<X<<endl<<flush;
  }else{
    cout<<"? "<<x<<" "<<y<<" "<<X<<" "<<Y<<endl<<flush;
  }
  int re;
  cin>>re;
  return re;
}

int n;
int lb(int y,int X,int Y,int v){
  int l=0,r=X,m;
  while(r-l>1){
    m=(l+r)/2;
    if(ask(m,y,X,Y)>=v) l=m;
    else r=m;
  }
  return l;
}
int ub(int x,int y,int Y,int v){
  int l=x,r=n,m;
  while(r-l>1){
    m=(l+r)/2;
    if(ask(x,y,m,Y)<v) l=m;
    else r=m;
  }
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  cin>>n;

  vector<int> x{lb(0,n,n,2),lb(0,n,n,1)};
  //cout<<x;
  vector<int> X{ub(0,0,n,1),ub(0,0,n,2)};
  //cout<<X;
  swp=1;
  vector<int> y{lb(0,n,n,2),lb(0,n,n,1)};
  //cout<<y;
  vector<int> Y{ub(0,0,n,1),ub(0,0,n,2)};
  //cout<<Y;
  swp=0;
  rep(i,2)rep(j,2)rep(k,2){
    if(ask(x[0],y[i],X[j],Y[k])==1 &&
       ask(x[1],y[1-i],X[1-j],Y[1-k])==1){
      cout<<"! "<<x[0]+1<<" "<<y[i]+1<<" "<<X[j]<<" "<<Y[k]<<" ";
      cout<<x[1]+1<<" "<<y[1-i]+1<<" "<<X[1-j]<<" "<<Y[1-k]<<endl;
      cout<<flush;
      return 0;
    }
  }
  return 0;
}