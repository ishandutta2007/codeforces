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

int dp[1<<16][133];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  fill(dp[0],dp[0]+(133<<16),-MOD);
  dp[0][0]=0;
  int n;
  cin>>n;
  vector<int> isb(n);
  vector<int> r(n),b(n);
  rep(i,n){
    string s;
    cin>>s>>r[i]>>b[i];
    isb[i]=(s[0]=='B');
  }
  rep(i,1<<n){
    int rc=0,bc=0;
    rep(j,n) if(i>>j&1) (isb[j]?bc:rc)++;
    //cout<<i<<pii(rc,bc)<<endl;
    rep(j,122)if(dp[i][j]>=0){
      rep(k,n){
	if(i>>k&1) continue;
	MX(dp[i|(1<<k)][j+min(rc,r[k])], dp[i][j]+min(bc,b[k]));
      }
    }
  }
  ll rc=accumulate(all(r),0ll);
  ll bc=accumulate(all(b),0ll);
  ll re=max(rc,bc);
  //rep(i,5){rep(j,1<<n) cout<<dp[j][i]<<",";cout<<endl;}
  rep(i,122) MN(re,max(rc-i,bc-dp[(1<<n)-1][i]));
  cout<<re+n<<endl;
  return 0;
}