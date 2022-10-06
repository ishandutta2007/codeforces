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
#define Endl endl

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
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while(getline(ss,x,c)) v.emplace_back(x); return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;
vector<int> vec[212345];

int ng;
int dfs(const vv<int> &g,int v,int p){
  vector<int> &a=vec[v];
  for(int w:g[v])if(w!=p) a.pb(dfs(g,w,v));
  sort(all(a)); UNIQUE(a);
  //out(v,a,1);
  if(a.size()==0){
    return 0;
  }else if(a.size()==1){
    return a[0]+1;
  }else{
    if(ng<0) ng=v;
    return -1;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vv<int> g(n);
  rep(i,n-1){
    int x,y;
    cin>>x>>y; --x; --y;
    g[x].pb(y);
    g[y].pb(x);
  }
  ng=-1;
  int re=dfs(g,0,-1);
  //out(re,ng,1);  
  if(ng>=0){
    rep(i,n) vec[i].clear();
    int root=ng; ng=-1;
    re=dfs(g,root,-1);
    if(ng!=root && ng!=-1 || vec[root].size()>2){
      cout<<-1<<endl;
      return 0;
    }
    if(vec[root].size()==2) re=vec[root][0]+vec[root][1]+2;
  }
  while(re%2==0) re/=2;
  cout<<re<<endl;
  // queue<int> que;
  // vector<int> ex(n,1);
  // vector<int> deg(n),num(n,-1);
  // rep(i,n){
  //   deg[i]=g[i].size();
  //   if(deg[i]==1){
  //     que.push(i);
  //     num[i]=0;
  //   }
  // }
  // while(que.size()){
  //   int v=que.front(); que.pop();
  //   vector<int> vs;
  //   for(int w:g[v])if(num[w]>=0) vs.pb(num[w]);
  //   sort(all(vs)); UNIQUE(vs);
  //   if(vs.size()<=1){

  //   }
  // }
  return 0;
}