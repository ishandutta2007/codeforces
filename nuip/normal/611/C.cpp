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

int v[512][512],h[512][512];

inline int fun(int d[512][512],int y,int x,int Y,int X){
  return d[X][Y]+d[x][y]-d[X][y]-d[x][Y];
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  vector<string> strs(n);
  rep(i,n) cin>>strs[i];
  
  //fill(v[0],v[0]+512*512,1);
  //fill(h[0],h[0]+512*512,1);
  rep(i,n)rep(j,m)if(strs[i][j]=='.'){
    if(i!=n-1 && strs[i+1][j]=='.')
      v[i+1][j+1]=1;
    if(j!=m-1 && strs[i][j+1]=='.')
      h[i+1][j+1]=1;
  }
  //rep(i,10){rep(j,10)cout<<v[i][j]<<",";cout<<endl;}cout<<endl;
  //rep(i,10){rep(j,10)cout<<h[i][j]<<",";cout<<endl;}cout<<endl;
  rep(i,n+1)rep(j,m+1){
    v[i][j+1]+=v[i][j];
    h[i][j+1]+=h[i][j];
  }
  rep(i,n+1)rep(j,m+1){
    v[i+1][j]+=v[i][j];
    h[i+1][j]+=h[i][j];
  }
  //rep(i,10){rep(j,10)cout<<v[i][j]<<",";cout<<endl;}cout<<endl;
  //rep(i,10){rep(j,10)cout<<h[i][j]<<",";cout<<endl;}cout<<endl;

  int q;
  int x,y,X,Y;
  cin>>q;
  while(q--){
    cin>>y>>x>>Y>>X; --x; --y;
    //out<<    fun(v,x,y,X,Y-1)<<","<<fun(h,x,y,X-1,Y)<<endl;
    cout<<fun(v,x,y,X,Y-1)+fun(h,x,y,X-1,Y)<<endl;
  }
  return 0;
}