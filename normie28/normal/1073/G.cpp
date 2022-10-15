// Problem : E. Chips Puzzle
// Contest : Codeforces - Mail.Ru Cup 2018 Round 1
// URL : https://codeforces.com/problemset/problem/1054/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
typedef long long i64;
#define Sz(a) ((int)(a).size())
const int maxn = 200009;
int sa[maxn],rnk[maxn],lcp[maxn];
int cc[maxn],xx[maxn],yy[maxn];
void SA(int n, int m, const string &s) {
  n++;
  int *c=cc,*x=xx,*y=yy;
  for (int i = 0; i < n; ++i) c[x[i] = s[i]]++;
  for (int i = 1; i < m; ++i) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
  for (int k = 1; k <= n; k <<= 1) {
    int p = 0;
    for (int i = n - k; i < n; ++i) y[p++] = i;
    for (int i = 0; i < n; ++i)
      if (sa[i] >= k) y[p++] = sa[i] - k;
    for (int i = 0; i < m; ++i) c[i] = 0;
    for (int i = 0; i < n; ++i) c[x[y[i]]]++;
    for (int i = 1; i < m; ++i) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
    swap(x, y);
    p = 1;
    x[sa[0]] = 0;
    for (int i = 1; i < n; ++i)
      x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
    if (p >= n) break;
    m = p;
  }
  n--;
  for (int i = 0; i <= n; ++i) rnk[sa[i]] = i;
  for (int i = 0, k = 0; i < n; ++i) {
    if (k) --k;
    int j = sa[rnk[i] - 1];
    while (s[i + k] == s[j + k]) ++k;
    lcp[rnk[i]] = k;
  }
}
const int LOGN=30;
int f[maxn][LOGN],logn[maxn];
int main(){
#ifdef DEBUG
  freopen("a.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
  int n,q;cin>>n>>q;
  string s;cin>>s;
  SA(n,400,s);
  logn[1]=0;logn[2]=1;
  for(int i=3;i<maxn;++i)logn[i]=logn[i/2]+1;
  for(int i=0;i<=n;++i)f[i][0]=lcp[i];
  for(int j=1;j<=LOGN;++j)for(int i=0;i+(1<<j)-1<=n;++i)
    f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
  auto rmq=[&](int a,int b)->int{
    int ss=logn[b-a+1];
    return min(f[a][ss],f[b-(1<<ss)+1][ss]);
  };
  auto getlcp=[&](int a,int b)->int{
    if(a==b)return n-a;
    a=rnk[a],b=rnk[b];
    return rmq(min(a,b)+1,max(a,b));
  };
  auto cal=[&](vector<int> &A)->i64{
    sort(A.begin(),A.end(),[&](int a,int b){return rnk[a]<rnk[b];});
    i64 res=0,cur=0;
    vector<pair<pair<int,int>,int>> que;
    que.push_back({{A[0],0},n-A[0]});
    for(int i=1;i<Sz(A);++i){
      int cnt=1,hg=n-A[i];
      while(Sz(que)){
        hg=getlcp(que.back().first.first,A[i]);
        if(hg>que.back().second)break;
        cur-=1ll*que.back().first.second*que.back().second;
        cnt+=que.back().first.second;
        que.pop_back();
      }
      cur+=1ll*hg*cnt;
      if(i!=0)res+=cur;
      que.push_back({{A[i],cnt},hg});
    }
    return res;
  };
  while(q--){
    int k,l;cin>>k>>l;
    vector<int> A(k),B(l);
    for(int i=0;i<k;++i)cin>>A[i],A[i]--;
    for(int i=0;i<l;++i)cin>>B[i],B[i]--;
    i64 res1=cal(A)+cal(B);
    for(int i=0;i<l;++i)A.push_back(B[i]);
    cout<<cal(A)-res1<<'\n';
  }
  return 0;
}