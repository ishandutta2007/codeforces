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
vector<int> primes,prime;
class PRPRPR{
public:
  PRPRPR(int PRIME_MAX){
    prime.resize(PRIME_MAX);
    for(int i=2;i<PRIME_MAX;i++)if(!prime[i]){
	primes.pb(i);
	for(int j=i*2;j<PRIME_MAX;j+=i)
	  prime[j]=1;
      }
  }
} prprprpr(1123456);

// int Fact(int x){
//   int re=0;
//   for(int p:primes){
//     if(x<1ll*p*p) break;
//     if(x%p) continue;
//     ++re;
//     while(x%p==0) x/=p;
//   }
//   if(x>1) ++re;
//   return re;
// }
// int Fact(int x,vector<int> &re){
//   for(int p:primes){
//     if(x<1ll*p*p) break;
//     if(x%p) continue;
//     re.eb();
//     while(x%p==0) x/=p, ++re.back();
//   }
//   if(x>1) re.pb(1);
// }
// ll modpow(ll r,ll n,ll m=MOD){
//   ll re=1,d=r%m;
//   if(n<0)(n%=m-1)+=m-1;
//   for(;n;n/=2){
//     if(n&1)(re*=d)%=m;
//     (d*=d)%=m;
//   }
//   return re;
// }

// ll fr(int r,int n){
//   if(!r) return modpow(2,Fact(n));
//   ll re=0;
//   reps(i,1,n+1){
//     if(i*i>n) break;
//     if(n%i) continue;
//     re+=fr(r-1,i);
//     if(i*i!=n) re+=fr(r-1,n/i);
//   }
//   re%=MOD;
//   //out(r,n,re,1);
//   return re;
// }

ll dp[1123456][22];
vector<int> facts[1123456];
ll pw[22];

int main(){
  // ios_base::sync_with_stdio(false);
  // cout<<fixed<<setprecision(0);
  dp[0][0]=1;
  reps(i,1,22) dp[0][i]=2;
  rep(i,1023456){
    rep(j,22) dp[i+1][j]=dp[i][j];
    rep(j,21) (dp[i+1][j+1]+=dp[i+1][j])%=MOD;
  }
  //rep(j,10) cout<<dp[2][j]<<",";cout<<endl;
  for(int p:primes){
    for(int i=p;i<1023456;i+=p) facts[i].pb(1);
    for(ll pw=1ll*p*p; pw<1023456; pw*=p)
      for(ll i=pw;i<1023456;i+=pw){
	++facts[i].back();
      }
  }
  pw[0]=1;
  rep(i,21) pw[i+1]=pw[i]*2%MOD;
  int T;
  scanf("%d",&T);
  while(T--){
    int r,n;
    scanf("%d%d",&r,&n);
    //cout<<fr(r,n)<<endl;
    if(!r){
      printf("%lld\n",pw[facts[n].size()]);
      continue;
    }
     // vector<int> fact;
     // Fact(n,fact);
     // cout<<fact<<facts[n]<<endl;
    ll re=1;
    for(int x:facts[n]) (re*=dp[r][x])%=MOD;
    printf("%I64d\n",re);
  }
  return 0;
}