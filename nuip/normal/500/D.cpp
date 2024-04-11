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

typedef vector<vector<pii>> Graph;

int dfs(Graph &g,int v,int p,vector<ll> &re){
  int ret=1;
  for(pii vv:g[v])if(vv.X!=p){
      ret+=dfs(g,vv.X,v,re);
    }
  return re[v]=ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(8);
  int i,j,k;
  int n,a,b,l;
  cin>>n;
  Graph g(n);
  vector<ll> len(n-1),ch(n);
  vector<pii> e; 
  rep(i,n-1){
    cin>>a>>b>>len[i];
    --a,--b;
    e.pb(pii(a,b));
    g[a].pb(pii(b,i));
    g[b].pb(pii(a,i));
  }
  dfs(g,0,-1,ch);
  double re=0;
  rep(i,n-1){
    int num=min(ch[e[i].X],ch[e[i].Y]);
    re+=len[i]*1.0*(num)*1.0*(n-num);
  }
  int q,d;
  cin>>q;
  rep(i,q){
    cin>>a>>b;
    --a;
    d=len[a]-b;
    len[a]=b;
    int num=min(ch[e[a].X],ch[e[a].Y]);
    //   cout<<e[a].X<<"<"<<e[a].Y<<":"<<num<<endl;
    re-=d*1.0*(num)*1.0*(n-num);
    cout<<re*6/(n-1)/n<<endl;
  }
  return 0;
}