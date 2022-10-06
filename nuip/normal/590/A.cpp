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
const  int INF=1e7;
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<int> a(n);
  vector<pii> t(n,pii(INF,2));
  rep(i,n) cin>>a[i];
  rep(i,n-1) if(a[i]==a[i+1]){
    t[i]=t[i+1]=pii(0,a[i]);
  }
  t[0]=pii(0,a[0]);
  t[n-1]=pii(0,a[n-1]);
  //cout<<t;
  rep(i,n-1)if(t[i+1].X>t[i].X+1){
    t[i+1]=t[i]; ++t[i+1].X;
  }
  //cout<<t;
  rrep(i,n-1)if(t[i].X>t[i+1].X+1){
    t[i]=t[i+1]; ++t[i].X;
  }
  int re=0;
  rep(i,n) re=max(re,t[i].X);
  cout<<re<<endl;
  rep(i,n){
    if(i)cout<<" ";
    cout<<t[i].Y;
  }
  cout<<endl;
  return 0;
}