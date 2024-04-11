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

int x;
int ok[1123456];
int c[1123456];
int root;

int dfs(vv<int> &g,int v){
  vector<int> oks;
  int sum=c[v];
  for(int w:g[v]){
    sum+=dfs(g,w);
    if(ok[w]>=0) oks.pb(ok[w]);
  }
  if(oks.size()>=2){
    cout<<oks[0]+1<<" "<<oks[1]+1<<endl;
    exit(0);
  }
  if(sum==x*2 && oks.size() && v!=root){
    cout<<oks[0]+1<<" "<<v+1<<endl;
    exit(0);
  }
  if(sum==x){
    ok[v]=v;
  }else if(oks.size()){
    ok[v]=oks[0];
  }else{
    ok[v]=-1;
  }
  return sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vv<int> g(n);
  rep(i,n){
    int x,y;
    cin>>x>>y;
    if(x) g[x-1].pb(i);
    else root=i;
    c[i]=y;
  }
  ll sum=accumulate(c,c+n,0);
  if(sum%3){
    cout<<-1<<endl;
    return 0;
  }
  x=sum/3;
  dfs(g,root);
  cout<<-1<<endl;
  return 0;
}