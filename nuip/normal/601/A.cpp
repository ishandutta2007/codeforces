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
const int INF=1e6;

int type[412][412],d[412][412][2];

typedef pair<pii,int> piii;
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m;
  cin>>n>>m;
  int x,y;
  rep(i,m){
    cin>>x>>y; --x; --y;
    type[x][y]=type[y][x]=1;
  }
  //rep(i,n){rep(j,n)cout<<type[i][j]<<",";cout<<endl;}
  fill(d[0][0],d[0][0]+412*412*2,INF);
  d[0][0][0]=0;
  queue<piii> que;
  que.emplace(pii(0,0),0);
  while(que.size()){
    piii p=que.front(); que.pop();
    int dd=d[p.X.Y][p.X.X][p.Y];
    if(p.Y){
      rep(v,n) if(type[p.X.X][v]==0 || p.X.X==v){
	if(d[p.X.Y][v][0]>dd && (p.X.Y!=v || v==n-1)){
	  d[p.X.Y][v][0]=dd;
	  que.emplace(pii(v,p.X.Y),0);
	}
      }
    }else{
      ++dd;
      rep(v,n) if(type[v][p.X.Y]==1 || p.X.Y==v){
	if(d[v][p.X.X][1]>dd && (p.X.X!=v || v==n-1)){
	  d[v][p.X.X][1]=dd;
	  que.emplace(pii(p.X.X,v),1);
	}
      }
    }
    //rep(i,n){rep(j,n)cout<<d[i][j][0]<<",";cout<<endl;}cout<<","<<endl;
    //rep(i,n){rep(j,n)cout<<d[i][j][1]<<",";cout<<endl;}cout<<endl;
  }
  int re=d[n-1][n-1][0];
  cout<<(re>=INF?-1:re)<<endl;
  return 0;
}