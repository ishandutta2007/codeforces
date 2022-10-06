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

int re[112][112];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m,q;
  cin>>n>>m>>q;
  vector<int> t(q),x(q);
  vector<pii> p(q);
  rep(i,q){
    cin>>t[i];
    if(t[i]==3){
      cin>>p[i].Y>>p[i].X;
      --p[i].X; --p[i].Y;
    }
    cin>>x[i];
    if(t[i]<3) --x[i];
  }
  // cout<<t<<x<<p;
  rrep(i,q){
    if(t[i]==3){
      re[p[i].Y][p[i].X]=x[i];
    }else if(t[i]==2){
      int tmp=re[n-1][x[i]];
      rrep(j,n-1) re[j+1][x[i]]=re[j][x[i]];
      re[0][x[i]]=tmp;
    }else{
      int tmp=re[x[i]][m-1];
      rrep(j,m-1) re[x[i]][j+1]=re[x[i]][j];
      re[x[i]][0]=tmp;
    }
  }

  rep(i,n){
    rep(j,m){
      if(j)cout<<" ";
      cout<<re[i][j];
    }cout<<endl;
  }
  return 0;
}