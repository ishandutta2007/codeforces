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
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define ef emplace_front
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

double dp[55][212345];

//get min
typedef pair<double,double> pdd;
struct CHT{
  deque<pdd> que; //p.X:decreasing, p.X * x + p.Y
  inline double eval(const pdd &p,const double &x){
    return p.X*x+p.Y;
  }
  double minv(double x){
    int n=que.size();
    if(n==1 || eval(que[n-2],x)>=eval(que[n-1],x)) return eval(que[n-1],x);
    int l=-1,r=n-2,m;
    while(r-l>1){
      m=(l+r)/2;
      if(eval(que[m],x)<eval(que[m+1],x)) r=m;
      else l=m;
    }
    return eval(que[r],x);
  }
  double min(double x){ //eNGx
    while(que.size()>1 && eval(que[0],x)>eval(que[1],x)) que.pop_front();
    return eval(que[0],x);
  }
  inline bool pop(const pdd &a,const pdd&b, const pdd &c){
    return (b.X-a.X)*(c.Y-b.Y)>=(b.Y-a.Y)*(c.X-b.X);
  }
  void pb(pdd p){
    while(que.size()>1 && pop(que[que.size()-2],que.back(),p)) que.pop_back();
    que.pb(p);
  }
  void pf(pdd p){
    while(que.size()>1 && pop(que[0],que[1],p)) que.pop_front();
    que.push_front(p);
  }
};
int main(){
  //ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int n,t;
  scanf("%d %d",&n,&t);
  vector<int> a(n);
  rep(i,n) scanf("%d",&a[i]);
  fill(dp[0],dp[0]+55*212345,1e300);
  dp[0][0]=0;

  vector<double> S(n+1),sum(n+1),is(n+1);
  rep(i,n){
    sum[i+1]=sum[i]+a[i];
    is[i+1]=is[i]+1./a[i];
    S[i+1]=S[i]+sum[i+1]/a[i];
  }

  CHT que[55];
  rep(i,n+1){
    rrep(j,t+1){
      double a=-sum[i],b=sum[i]*is[i]-S[i]+dp[j][i];
      que[j].pb(pdd(a,b));
      MN(dp[j+1][i+1],S[i+1]+que[j].min(is[i+1]));
    }
  }
  //rep(i,t+1){rep(j,n+1)cout<<dp[i][j]<<",";cout<<endl;}
  cout<<dp[t][n]<<endl;
  return 0;
}