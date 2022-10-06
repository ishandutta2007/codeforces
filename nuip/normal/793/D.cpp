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
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
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

int dp[88][88][88][2]; //0 : left

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,t,m;
  cin>>n>>t>>m;
  vv<pii> g(n);
  rep(i,m){
    int x,y,z;
    cin>>x>>y>>z; --x; --y;
    g[y].eb(x,z);
  }
  //rep(i,n) sort(all(g[i]));
  fill(dp[0][0][0],dp[0][0][0]+88*88*88*2,MOD);
  rep(i,n)rep(j,2) dp[1][i][i][j]=0;
  reps(i,1,t)rep(l,n)reps(r,l,n){
    for(pii p:g[l]){
      if(p.X<l) MN(dp[i+1][p.X][r][0],dp[i][l][r][0]+p.Y);
      if(p.X>r) MN(dp[i+1][l][p.X][1],dp[i][l][r][0]+p.Y);
    }
    for(pii p:g[r]){
      if(p.X<l) MN(dp[i+1][p.X][r][0],dp[i][l][r][1]+p.Y);
      if(p.X>r) MN(dp[i+1][l][p.X][1],dp[i][l][r][1]+p.Y);
    }
  }
  //reps(i,2,4){rep(l,n){rep(r,n)cout<<pii(dp[i][l][r][0],dp[i][l][r][1]);cout<<endl;}cout<<endl;}
  int re=*min_element(dp[t][0][0],dp[t][0][0]+88*88*2);
  cout<<(re==MOD?-1:re)<<endl;
  return 0;
}