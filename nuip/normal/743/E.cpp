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

int nxt[8][1123][1123];
int dp[1<<8][1123];

ll fun(int m){
    vector<int> dp(1<<8,MOD);
    dp[0]=0;
    rep(i,1<<8)if(dp[i]<MOD){
      rep(j,8) if(!(i>>j&1)){
	MN(dp[i|(1<<j)], nxt[j][dp[i]][m]);
	MN(dp[i|(1<<j)], nxt[j][dp[i]][m+1]);
      }
    }
    //if(m==1) cout<<dp;
    return dp[(1<<8)-1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i], --a[i];
  fill(nxt[0][0],nxt[0][0]+1123*1123*8,MOD);
  //rep(j,3){rep(i,n) cout<<nxt[0][i][j]<<",";cout<<endl;}
  vector<int> vs(8,MOD);
  rrep(i,n){
    vs[a[i]]=i;
    rep(j,8){
      nxt[j][i][0]=i;
      nxt[j][i][1]=vs[j]+1;
      //cout<<nxt[j][i][1]<<endl;
      if(vs[j]<MOD) reps(k,2,1023) if((nxt[j][i][k]=nxt[j][nxt[j][i][k-1]][1])>=MOD) break;
    }
  }
  int l=0,r=n/8+1;
  while(r-l>1){
    int m=(l+r)/2;
    if(fun(m)<MOD) l=m;
    else r=m;
  }
  //cout<<l<<endl;
  //rep(j,3){rep(i,n) cout<<nxt[0][i][j]<<",";cout<<endl;}

  fill(dp[0],dp[0]+(1123<<8),-MOD);
  dp[0][0]=0;
  rep(j,1<<8)rep(i,n)if(dp[j][i]>=0){
    rep(k,8) if(!(j>>k&1)){
      int tmp=nxt[k][i][l];
      if(tmp<MOD) MX(dp[j|(1<<k)][tmp],dp[j][i]+l);
      tmp=nxt[k][i][l+1];
      if(tmp<MOD) MX(dp[j|(1<<k)][tmp],dp[j][i]+l+1);
    }
  }
  cout<<*max_element(dp[(1<<8)-1],dp[(1<<8)-1]+n+1)<<endl;
  return 0;
}