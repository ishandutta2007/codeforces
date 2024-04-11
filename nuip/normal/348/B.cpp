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

typedef vector<vector<int>> Graph;

vector<ll> v;
Graph g;

ll INF=1e13+10;

pll dfs(int w,int p){
  ll lcm=1,cnt=0,mn=INF;
  pll re,tmp;
  for(int ww:g[w])if(ww!=p){
      ++cnt;
      tmp=dfs(ww,w);
      lcm*=tmp.Y/__gcd(tmp.Y,lcm);
      mn=min(mn,tmp.X);
      if(lcm>INF)
	return pll(0,1);
    }
  if(cnt==0)
    return pll(v[w],1);
  return pll(mn/lcm*lcm*cnt,lcm*cnt);
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n;
  cin>>n;
  v.resize(n);
  g.resize(n);
  rep(i,n)
    cin>>v[i];
  int a,b;
  rep(i,n-1){
    cin>>a>>b;
    --a,--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  cout<<accumulate(all(v),0ll)-dfs(0,-1).X<<endl;
  return 0;
}