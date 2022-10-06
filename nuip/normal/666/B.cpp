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
int d[3123][3123];
void upd(vector<pii> re[3],pii d,int t){
  if(d.X>=MOD) return;
  if(d>=re[0][t]){
    re[2][t]=re[1][t];
    re[1][t]=re[0][t];
    re[0][t]=d;
  }else if(d>=re[1][t]){
    re[2][t]=re[1][t];
    re[1][t]=d;
  }else if(d>re[2][t]){
    re[2][t]=d;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  vv<int> g(n);
  int x,y;
  rep(i,m){
    cin>>x>>y; --x; --y;
    g[x].pb(y);
  }
  fill(d[0],d[0]+3123*3123,MOD);
  rep(s,n){
    queue<int> que;
    que.emplace(s);
    d[s][s]=0;
    while(que.size()){
      int x=que.front(); que.pop();
      for(int y:g[x])
	if(MN(d[s][y],d[s][x]+1)) que.emplace(y);
    }
  }
  //rep(i,n){rep(j,n)cout<<d[i][j]<<",";cout<<endl;}
  vector<pii> din[3],dout[3];
  rep(i,3){
    din[i].resize(n);
    dout[i].resize(n);
  }
  rep(i,n)rep(j,n)if(i!=j){
    upd(din,pii(d[j][i],j),i);
    upd(dout,pii(d[i][j],j),i);
  }
  ll re=-1;
  vector<int> rev;
  rep(i,n) rep(j,n) if(i!=j && d[i][j]<MOD){
    rep(a,3)rep(b,3){
      const pii p=din[a][i],q=dout[b][j];
      if(p.X==0 || q.X==0) continue;
      if(p.Y==j || p.Y==q.Y || q.Y==i) continue;
      if(MX(re,d[i][j]+p.X+q.X+0ll)){
	rev={p.Y,i,j,q.Y};
      }
    }
  }
  //cout<<re<<endl;
  rep(i,4){
    if(i) cout<<" ";
    cout<<rev[i]+1;
  }
  cout<<endl;
  return 0;
}