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
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;

int n,m;
vector<string> mp;
int swpx,swpy;

pii ask(char c){
  cout<<c<<endl;
  int x,y;
  cin>>x>>y;
  if(x<0 || mp[x][y]=='F') exit(0);
  return pii(y,x);
}

pii move(char c){
  if(c=='R') cout<<"RL"[swpx]<<endl;
  if(c=='L') cout<<"LR"[swpx]<<endl;
  if(c=='U') cout<<"UD"[swpy]<<endl;
  if(c=='D') cout<<"DU"[swpy]<<endl;
  int x,y;
  cin>>x>>y;
  if(x<0 || mp[x][y]=='F') exit(0);
  return pii(y,x);
}
int sx,sy;
int usd[111][111];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int dfs(int x,int y){
  if(mp[y][x]=='*' || usd[y][x]) return 0;
  if(sx==x && sy==y) return 1;
  usd[y][x]=1;
  rep(d,4)if(dfs(x+dx[d],y+dy[d])){
    assert(move("LURD"[d])==pii(x,y));
    return 1;
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  cin>>n>>m;
  mp.resize(n+2);
  mp[0]=mp[n+1]=string(m+2,'*');
  rep(i,n){
    string s;
    cin>>s;
    mp[i+1]="*"+s+"*";
  }
  //for(auto s:mp) cout<<s<<endl;
  int x,y;
  if(mp[1][2]!='*'){
    tie(x,y)=ask('R');
    if(x==1){
      swpx=1;
    }else{
      tie(x,y)=ask('L');
    }
    while(mp[y+1][x]=='*') tie(x,y)=move('R');
    tie(x,y)=ask('D');
    if(y==1){
      swpy=1;
    }
  }else{
    tie(x,y)=ask('D');
    if(y==1){
      swpy=1;
    }else{
      tie(x,y)=ask('U');
    }
    while(mp[y][x+1]=='*') tie(x,y)=move('D');
    tie(x,y)=ask('R');
    if(x==1){
      swpx=1;
    }
  }
  sx=x; sy=y;
  rep(i,n)rep(j,m)if(mp[i+1][j+1]=='F') dfs(j+1,i+1);
  //cout<<"fail"<<endl;
  return 0;
}