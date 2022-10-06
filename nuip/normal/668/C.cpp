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
  cout<<fixed<<setprecision(10);
  int n;
  cin>>n;
  vector<double> M(n+1),m(n+1);
  rep(i,n) cin>>M[i];
  rep(i,n) cin>>m[i];
  rrep(i,n)
    m[i]+=m[i+1];
  rep(i,n)
    M[i+1]+=M[i];

  //cout<<M<<m;
  vector<double> A(n),B(n);
  rep(i,n){
    double b=-(M[i]-m[i+1]+1)/2;
    double c=M[i];
    double D=max(0.,b*b-c);
    //if(D<0) cout<<"!!!!"<<endl;
    //cout<<b<<","<<c<<","<<D<<endl;
    D=sqrt(D);
    A[i]=-b+D;
    B[i]=-b-D;
    //cout<<A[i]*B[i]<<","<<A[i]+B[i]<<endl;
    //cout<<c<<","<<-b*2<<endl;
  }
  //cout<<A<<B;
  rrep(i,n-1){
    A[i+1]-=A[i];
    B[i+1]-=B[i];
  }
  //cout<<A<<B;
  rep(i,n){
    if(i)cout<<" ";
    cout<<A[i];
  }cout<<endl;
  rep(i,n){
    if(i)cout<<" ";
    cout<<B[i];
  }cout<<endl;
  return 0;
}