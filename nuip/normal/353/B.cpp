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
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n;
  cin>>n;
  vector<int> l[3],b,re(2*n);
  vector<pii> a(2*n);
  rep(i,2*n){
    cin>>a[i].X;
    a[i].Y=i;
  }
  sort(all(a));
  b.pb(a[0].X),b.pb(a[1].Y);
  l[0].pb(a[0].Y),l[1].pb(a[1].Y);
  rep(i,2*n-2)
    if(a[i].X!=a[i+2].X){
      l[b.size()%2].pb(a[i+2].Y);
      b.pb(a[i+2].X);
    }else{
      l[2].pb(a[i+2].Y);
    }
  rep(i,2)
    while(l[i].size()<n){
      l[i].pb(l[2].back());
      l[2].pop_back();
    }
  //  rep(i,2)cout<<l[i];
  rep(i,2)
    rep(j,n)
    re[l[i][j]]=i+1;
  cout<<(b.size()/2)*((b.size()+1)/2)<<endl;
  rep(i,2*n)
    cout<<re[i]<<" ";cout<<endl;
  return 0;
}