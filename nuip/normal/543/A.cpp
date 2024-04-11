
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
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
int dp[2][512][512];
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,m,b,mod;
  scanf("%d%d%d%d",&n,&m,&b,&mod);
  int a[n];
  rep(i,n)
    scanf("%d",a+i);
  dp[0][0][0]=1;
  int l=0,sum;
  rep(i,m){
    l=1-l;
    fill(dp[l][0],dp[l][0]+512*512,0);
    rep(p,n)rep(i,b+1){
      (dp[1-l][p+1][i]+=dp[1-l][p][i])%=mod;
      if(i+a[p]<510)
	(dp[l][p][i+a[p]]+=dp[1-l][p][i])%=mod;
    }
    //rep(p,n){rep(i,b+1)cout<<dp[l][p][i]<<",";cout<<endl;}cout<<endl;
  }

  int re=0;
  l=m%2;
  rep(p,n)rep(i,b+1)
    (re+=dp[l][p][i])%=mod;
  printf("%d\n",re);
  return 0;
}