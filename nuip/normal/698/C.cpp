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
const double EPS=1e-7;

double p[1<<20];
double ad[1<<20];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int n,t;
  cin>>n>>t;
  vector<double> a(n);
  double ng=0;
  rep(i,n) cin>>a[i];
  p[0]=1;
  int f=0;
  rep(i,1<<n){
    const int pop=__builtin_popcount(i);
    if(pop>t) continue;
    double stay=0;
    rep(j,n) if(i>>j&1) stay+=a[j];
    if(1-stay<EPS){
      f=i;
      break;
    }
    rep(j,n) if(!(i>>j&1)) p[i|(1<<j)]+=p[i]*a[j]/(1-stay);
  }
  //rep(i,1<<n) cout<<p[i]<<",";cout<<endl;
  //rep(i,1<<n) cout<<ad[i]<<",";cout<<endl;
  if(f){
    rep(i,n) cout<<double(f>>i&1)<<" ";cout<<endl;
    return 0;
  }
  double sum=0;
  vector<double> re(n);
  rep(i,1<<n) if(__builtin_popcount(i)==t){
    sum+=p[i];
    rep(j,n) if(i>>j&1) re[j]+=p[i];
  }
  //cout<<sum<<re;
  rep(i,n) cout<<re[i]/sum<<" ";cout<<endl;
  return 0;
}



// int main(){
//   ios_base::sync_with_stdio(false);
//   cout<<fixed<<setprecision(10);
//   int n,t;
//   cin>>n>>t;
//   vector<double> a(n);
//   double ng=0;
//   rep(i,n) cin>>a[i];
//   ad[0]=1;
//   int f=0;
//   rep(i,1<<n){
//     if(__builtin_popcount(i)>t) continue;
//     double stay=0;
//     rep(j,n) if(i>>j&1) stay+=a[j];
//     if(1-stay>EPS) p[i]=ad[i]/(1-stay);
//     else f=i;
//     rep(j,n) if(!(i>>j&1)) ad[i|(1<<j)]+=p[i]*a[j];
//   }
//   rep(i,1<<n) cout<<p[i]<<",";cout<<endl;
//   rep(i,1<<n) cout<<ad[i]<<",";cout<<endl;
//   if(f){
//     rep(i,n) cout<<(f>>i&1)<<" ";cout<<endl;
//     return 0;
//   }
//   double sum=accumulate(p,p+(1<<20),(double)0);
//   vector<double> re(n);
//   rep(i,1<<n) rep(j,n) if(i>>j&1) re[j]+=p[i];
//   cout<<sum<<re;
//   rep(i,n) cout<<re[i]/sum<<" ";cout<<endl;
//   return 0;
// }