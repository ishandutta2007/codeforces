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
const int INF=1e7;
int n,m;
int dy[]={0,1,0,-1},dx[]={1,0,-1,0};
void findd(vv<int> &re,const vector<string> &mp,char c){
  re.resize(n,vector<int>(m,INF));
  queue<pii> que;
  rep(i,n)rep(j,m)
    if(mp[i][j]==c){
      re[i][j]=0;
      que.emplace(j,i);
    }
  //cout<<c<<endl<<mp<<re;
  while(que.size()){
    pii p=que.front(); que.pop();
    rep(d,4){
      int y=p.Y+dy[d],x=p.X+dx[d];
      if(y<0 || n<=y || x<0 || m<=x 
|| re[y][x]<=re[p.Y][p.X]+1 || mp[y][x]=='#') continue;
      re[y][x]=re[p.Y][p.X]+1;
      que.emplace(x,y);
    }
  }
  //cout<<c<<endl<<re;
}

int minf(const vv<int> &v,const vv<int> &w){
  int re=INF;
  rep(i,n)rep(j,m)
    re=min(re,v[i][j]+w[i][j]-1);
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  cin>>n>>m;
  vector<string> mp(n);
  rep(i,n)
    cin>>mp[i];
  vv<int> d[3];
  rep(i,3)
    findd(d[i],mp,'1'+i);
  vector<int> v={minf(d[0],d[1]),
		 minf(d[1],d[2]),
		 minf(d[0],d[2])};
  sort(all(v));
  int re=v[0]+v[1];
  //cout<<re<<endl;
  rep(i,n)rep(j,m)
    re=min(re,d[0][i][j]+d[1][i][j]+d[2][i][j]-2);
  cout<<(re>=INF-10?-1:re)<<endl;
  return 0;
}