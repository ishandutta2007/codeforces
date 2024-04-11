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
const ll INF=1e15;

ll sum[212345],one[212345];

ll dfs(vv<int> &g,vector<ll> &a,int v,int p){
  ll re=a[v],tmp;
  vector<ll> vec;
  for(int w:g[v]) if(w!=p){
      re+=tmp=dfs(g,a,w,v);
      vec.pb(one[w]);
    }
  sort(rall(vec));
  if(vec.size()) MX(one[v],vec[0]);
  if(vec.size()>=2) MX(sum[v],vec[0]+vec[1]);
  MX(one[v],re);
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  fill(sum,sum+212345,-INF);
  fill(one,one+212345,-INF);
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  vv<int> g(n);
  rep(i,n-1){
    int x,y;
    cin>>x>>y; --x; --y;
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs(g,a,0,-1);
  //rep(i,n) cout<<sum[i]<<",";cout<<endl;
  //rep(i,n) cout<<one[i]<<",";cout<<endl;
  ll re=*max_element(sum,sum+n);
  if(re==-INF){
    cout<<"Impossible"<<endl;
  }else{
    cout<<re<<endl;
  }
  return 0;
}