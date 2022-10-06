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
#define REP(X,Y) for (int (X) = 0;(X) < (Y);++(X))
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
const ll MOD=1e9+7;
// Larsson-Sadakane's Suffix array Construction: O(n (log n)^2)
struct SAComp {
  const int h, *g;
  SAComp(int h, int* g) : h(h), g(g) {}
  bool operator() (int a, int b) {
    return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a+h] < g[b+h];
  }
};
int *buildSA(char* t, int n) {
  int g[n+1], b[n+1], *v = new int[n+1];
  REP(i,n+1) v[i] = i, g[i] = t[i];
  b[0] = 0; b[n] = 0;

  sort(v, v+n+1, SAComp(0, g));
  for(int h = 1; b[n] != n ; h *= 2) {
    SAComp comp(h, g);
    sort(v, v+n+1, comp);
    REP(i, n) b[i+1] = b[i] + comp(v[i], v[i+1]);
    REP(i, n+1) g[v[i]] = b[i];
  }
  return v;
}

// Kasai-Lee-Arimura-Arikawa-Park's simple LCP computation: O(n)
int *buildLCP(char *t, int n, int *a) {
  int h = 0, b[n+1], *lcp = new int[n+1];
  REP(i, n+1) b[a[i]] = i;
  REP(i, n+1) {
    if (b[i]){
      for (int j = a[b[i]-1]; j+h<n && i+h<n && t[j+h] == t[i+h]; ++h);
      lcp[b[i]] = h;
    } else lcp[b[i]] = -1;
    if (h > 0) --h;
  }
  return lcp;
}
// call RMQ = buildRMQ(lcp, n+1)
int *buildRMQ(int *a, int n) {
  int logn = 1;
  for (int k = 1; k < n; k *= 2) ++logn;
  int *r = new int[n * logn];
  int *b = r; copy(a, a+n, b);
  for (int k = 1; k < n; k *= 2) {
    copy(b, b+n, b+n); b += n;
    REP(i, n-k) b[i] = min(b[i], b[i+k]);
  }
  return r;
}
// inner LCP computation with RMQ: O(1)
int minimum(int x, int y, int *rmq, int n) {
  int z = y - x, k = 0, e = 1, s; // y - x >= e = 2^k  k
  s = ( (z & 0xffff0000) != 0 ) << 4; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000ff00) != 0 ) << 3; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x000000f0) != 0 ) << 2; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000000c) != 0 ) << 1; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x00000002) != 0 ) << 0; z >>= s; e <<= s; k |= s;
  return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}
// outer LCP computation: O(m - o)
int computeLCP(char *t, int n, char *p, int m, int o, int k) {
  int i = o;
  for (; i < m && k+i < n && p[i] == t[k+i]; ++i);
  return i;
}
int lcps[5123][5123];
ll dp[5123][5123],sum[5123][5123];//end,[0,length)
char str[5123];
int main(){
  //ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  scanf("%d %s",&n,str);
  int *sa=buildSA(str,n);
  vector<int> inv(n+1);
  rep(i,n+1) inv[sa[i]]=i;
  int *lcp=buildLCP(str,n,sa);
  int *rmq=buildRMQ(lcp,n+1);
  //rep(i,n)cout<<sa[i]<<endl;
  rep(i,n)rep(j,i){
    int l=inv[j],r=inv[i];
    if(l>r) swap(l,r);
    lcps[j][i]=lcps[i][j]=minimum(l+1,r,rmq,n+1);
  }
  //rep(i,n){rep(j,n)cout<<lcps[i][j]<<",";cout<<endl;}cout<<endl;

  rep(i,n+1)if(i)
    dp[0][i]=1;
  rep(i,n+1)if(str[i]!='0')rrep(j,i){
    int len=i-j;
    if(j-len>=0){
      const int hoge= lcps[j-len][j];
      if(hoge<len && str[j-len+hoge]<str[j+hoge]){
	//cout<<pii(j-len,j) <<pii(j,i)<<endl;
	(dp[j][i]+=dp[j-len][j])%=MOD;
      }
    }
    (dp[j][i]+=sum[j][len])%=MOD;
    (sum[i][len+1]+=dp[j][i]+sum[i][len])%=MOD;
     if(!j)for(int k=len+1;k<n;++k)
	     sum[i][k+1]+=sum[i][k];

  }
  // rep(i,n+1){rep(j,n+1)cout<<dp[i][j]<<",";cout<<endl;}cout<<endl;
  //rep(i,n+1){rep(j,n+1)cout<<sum[i][j]<<",";cout<<endl;}cout<<endl;
  ll re=0;
  rep(i,n) (re+=dp[i][n])%=MOD;
  (re+=MOD)%=MOD;
  printf("%I64d\n",re);
  return 0;
}