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

ll dp[10][1<<20];
ll sum[10][1<<20];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  // vector<int> v;
  // reps(i,1,10){
  //   rep(j,1<<(i-1)){
  //     v.pb(i);
  //     if(accumulate(all(v),0)>75) break;
  //   }
  //     if(accumulate(all(v),0)>75) break;
  // }
  // cout<<v.size()<<v;
  int n;
  string s;
  cin>>n>>s;
  dp[0][0]=1;
  ll re=0;
  rep(i,n){
    (dp[(i+1)%10][0]+=1)%=MOD;
    rep(j,1<<20) dp[i%10][j]%=MOD;
    //for(int j=2;j<=(1<<20);j*=2) if(dp[i][j-1])out(i,j-1,dp[i][j-1],1);
    if(s[i]=='0'){
      rep(k,1<<20) (sum[(i+1)%10][k]+=dp[i%10][k]+sum[i%10][k])%=MOD;
    }else{
      int val=0;
      reps(j,i,n){
	(val*=2)+=s[j]-'0';
	if(val>20) break;
	rep(k,1<<20) dp[(j+1)%10][k|(1<<(val-1))]+=dp[i%10][k]+sum[i%10][k];
      }
    }
    for(int j=2;j<=(1<<20);j*=2) (re+=dp[i%10][j-1])%=MOD;
    fill(dp[i%10],dp[i%10]+(1<<20),0);
    fill(sum[i%10],sum[i%10]+(1<<20),0);
  }
  //rep(i,n+1){rep(j,8) cout<<dp[i][j]<<",";cout<<endl;}
  for(int i=2;i<(1<<20);i*=2) (re+=dp[n%10][i-1])%=MOD;
  //rep(j,n+1)for(int i=2;i<=(1<<20);i*=2) if(dp[j][i-1])out(j,i-1,dp[j][i-1],1);
  cout<<re<<endl;
  return 0;
}
//  <= 19