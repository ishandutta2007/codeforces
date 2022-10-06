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
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,m,x,y;
  cin>>n>>m;
  vv<int> g(n),d(n);
  rep(i,m){
    cin>>x>>y;
    --x; --y;
    g[x].pb(y);
    g[y].pb(x);
  }
  rep(i,n){
    d[i].resize(n,-1);
    d[i][i]=0;
    queue<int> que;
    que.push(i);
    while(!que.empty()){
      int v=que.front(); que.pop();
      for(int w:g[v])
	if(d[i][w]<0){
	  d[i][w]=d[i][v]+1;
	  que.push(w);
	}
    }
  }
  //cout<<d;

  vector<int> s(2),t(2),l(2);
  int re=0;
  rep(i,2){
    cin>>s[i]>>t[i]>>l[i];
    --s[i]; --t[i];
    if(d[s[i]][t[i]]>l[i]){
      cout<<-1<<endl;
      return 0;
    }
    re+=d[s[i]][t[i]];
  }
  rep(i,n)rep(j,n){
    int d1=d[i][j]+d[s[0]][i]+d[j][t[0]],
      d2=d[i][j]+d[s[1]][i]+d[j][t[1]];
    if(d1<=l[0] && d2<=l[1])
      re=min(re,d1+d2-d[i][j]);
    d2=d[i][j]+d[s[1]][j]+d[i][t[1]];
    if(d1<=l[0] && d2<=l[1])
      re=min(re,d1+d2-d[i][j]);
  }
  cout<<m-re<<endl;
  return 0;
}