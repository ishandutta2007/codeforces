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
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

void buildFail(string &p,vector<int> &fail) {
  int m = p.size();
  fail.resize(m+1);
  int j = fail[0] = -1;
  for (int i = 1; i <= m; ++i) {
    while (j >= 0 && p[j] != p[i-1]) j = fail[j];
    fail[i] = ++j;
  }
}
int match(string &t, string &p, vector<int> &fail,vector<int> &re) {
  int n = t.size(), m = p.size();
  re.resize(n);
  int count = 0;
  for (int i = 0, k = 0; i < n; ++i) {
    while (k >= 0 && p[k] != t[i]) k = fail[k];
    if (++k >= m) {
      ++count; // match at t[i-m+1 .. i]
      re[i]=1;
      k = fail[k];
    }
  }
  return count;
}
ll dp[112345],sum[112345],sum2[112345],MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  string s,t;
  cin>>s>>t;
  int n=s.size(),m=t.size();
  vector<int> fail,ist;
  buildFail(t,fail);
  match(s,t,fail,ist);
//  cout<<ist;

  dp[0]=0;
  sum[0]=sum2[0]=1;
  rep(i,n){
    if(ist[i]){
      (dp[i+1]+=sum2[i-m+1])%=MOD;
    }else{
      (dp[i+1]+=dp[i])%=MOD;
    }
    sum[i+1]=(sum[i]+dp[i+1])%MOD;
    sum2[i+1]=(sum2[i]+sum[i+1])%MOD;
  }
 /* rep(i,n+1)cout<<dp[i]<<",";cout<<endl;
  rep(i,n+1)cout<<sum[i]<<",";cout<<endl;
  rep(i,n+1)cout<<sum2[i]<<",";cout<<endl;*/
  cout<<(sum[n]+MOD-1)%MOD<<endl;
  return 0;
}