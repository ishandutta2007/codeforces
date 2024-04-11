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

void dfs(Graph &g,vector<int> &val,int v,int p,int n,int m,vector<int> &re){
  // cout<<v<<","<<n<<","<<m<<endl;
  if(val[v]!=n){
    re.pb(v);
    n=1-n;
  }
  for(int vv:g[v])
    if(vv!=p)
      dfs(g,val,vv,v,m,n,re);
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,a,b;
  cin>>n;
  Graph g(n);
  vector<int> v(n);
  rep(i,n-1){
    cin>>a>>b;
    --a,--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  rep(i,n)
    cin>>v[i];
  rep(i,n){
    cin>>a;
    v[i]^=a;
  }
  //  cout<<v;
  vector<int> re;
  dfs(g,v,0,-1,0,0,re);
  cout<<re.size()<<endl;
  for(int a:re)
    cout<<a+1<<endl;
 return 0;
}