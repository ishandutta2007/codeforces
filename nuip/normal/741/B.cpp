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

struct UF{
  vector<int> data;
  UF(int size):data(size,-1){}
  bool unite(int x,int y){
    x=root(x); y=root(y);
    if(x!=y){
      if(data[y]<data[x]) swap(x,y);
      data[x]+=data[y]; data[y]=x;
    }
    return x!=y;
  }
  bool findSet(int x,int y){return root(x)==root(y);}
  int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
  int size(int x) {return -data[root(x)];}
};

ll dp[2222][2222];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m,ub;
  cin>>n>>m>>ub;
  vector<ll> w(n),b(n);
  rep(i,n) cin>>w[i];
  rep(i,n) cin>>b[i];
  UF uf(n);
  rep(i,m){
    int x,y;
    cin>>x>>y; --x; --y;
    uf.unite(x,y);
  }
  vv<pll> W(n);
  rep(i,n){
    W[uf.root(i)].eb(w[i],b[i]);
  }
  //cout<<W;
  rep(i,n){
    rep(j,ub+1) dp[i+1][j]=dp[i][j];
    if(W[i].size()==0) continue;
    pll tmp;
    for(pll p:W[i]) tmp.X+=p.X, tmp.Y+=p.Y;
    W[i].pb(tmp);
    //cout<<W[i];
    for(pll p:W[i]){
      rep(j,ub+1-p.X) MX(dp[i+1][j+p.X],dp[i][j]+p.Y);
    }
  }
  cout<<*max_element(dp[n],dp[n]+ub+1)<<endl;
  return 0;
}