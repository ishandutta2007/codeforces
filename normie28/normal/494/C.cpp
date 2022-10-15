// Problem: C. Helping People
// Contest: Codeforces - Codeforces Round #282 (Div. 1)
// URL: https://codeforces.com/contest/494/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
int n,a[100005],q,l[5005],r[5005],st[100005][25];
double dp[5005][5005];
struct Q{
    int l,r,Max;
    double p;
}d[5005];
int log(int a){
    if(a>=(1<<16))return log(a>>16)+16;
    if(a>=(1<<8))return log(a>>8)+8;
    if(a>=(1<<4))return log(a>>4)+4;
    if(a>=(1<<2))return log(a>>2)+2;
    if(a>=(1<<1))return log(a>>1)+1;
    return 0;
}
int rmq(int l,int r){
    return max(st[l][log(r-l+1)],st[r-(1<<log(r-l+1))+1][log(r-l+1)]);
}
bool cmp(Q a,Q b){
    if(a.l!=b.l)return a.l<b.l;
    return a.r>b.r;
}
int to[10005],nxt[10005],head[5005],cnt;
void add(int a,int b){
    to[++cnt]=b;
    nxt[cnt]=head[a];
    head[a]=cnt;
}
stack<int> s;
double safedp(int a,int b){
    if(b>q)return dp[a][q];
    if(b<0)return 0;
    return dp[a][b];
}
void dfs(int u){
    for(int i=head[u];i;i=nxt[i])dfs(to[i]);
    for(int i=0;i<=q;i++){
        double tmp=1;
        if(i!=0){for(int j=head[u];j;j=nxt[j])tmp*=safedp(to[j],i+d[u].Max-d[to[j]].Max-1);
        dp[u][i]+=d[u].p*tmp;}
        tmp=1;
        for(int j=head[u];j;j=nxt[j])tmp*=safedp(to[j],i+d[u].Max-d[to[j]].Max);
        dp[u][i]+=(1-d[u].p)*tmp;
    }
}
int main(){
	fio;
	cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)st[i][0]=a[i];
    for(int i=1;i<=20;i++)for(int j=1;j<=n-(1<<i)+1;j++)st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    for(int i=1;i<=q;i++) cin>>d[i].l>>d[i].r>>d[i].p,d[i].Max=rmq(d[i].l,d[i].r);
    q++;
    d[q].l=1,d[q].r=n,d[q].p=0,d[q].Max=rmq(1,n);
    sort(d+1,d+q+1,cmp);
    s.push(1);
    for(int i=2;i<=q;i++){
        while(!(d[s.top()].l<=d[i].l&&d[s.top()].r>=d[i].r))s.pop();
        add(s.top(),i);
        s.push(i);
    }
    dfs(1);
    double ans=0;
    for(int i=0;i<=q;i++)ans+=i*(safedp(1,i)-safedp(1,i-1));
    cout<<fixed<<setprecision(9)<<ans+d[1].Max;
}