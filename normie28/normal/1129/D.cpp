
// Problem : D. Isolation
// Contest : Codeforces - Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 1)
// URL : https://codeforces.com/problemset/problem/1129/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
#define rt register int
#define l putchar('\n')
#define r read()
#define p 998244353
typedef long long ll;
//---------END-------//
inline ll read(){
    ll x=0;char zf=1;char ch=getchar();
    while(ch!='-'&&!isdigit(ch))ch=getchar();
    if(ch=='-')zf=-1,ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();return x*zf;
}

void write(ll y){if(y<0)putchar('-'),y=-y;if(y>9)write(y/10);putchar(y%10+48);}

void writeln(const ll y){write(y);putchar('\n');}

int k,m,n,x,y,z,cnt,ans;
int la[100010],now[100010],v[100010],s[100010],dp[100010];
int f[400][100010],tag[350],blo,maxs[350],id[100010];

void build(int x){
	int Min=1000000000,Max=-1000000000;
	for(rt i=x*blo;i<(x+1)*blo;i++){
		if(s[i]<Min)Min=s[i];
		if(s[i]>Max)Max=s[i];
	}
	maxs[x]=Max-Min;
	for(rt i=0;i<=maxs[x];i++)f[x][i]=0;
	tag[x]+=Min;
	for(rt i=x*blo;i<(x+1)*blo;i++)s[i]-=Min,(f[x][s[i]]+=dp[i])%=p;
	for(rt i=1;i<=Max-Min;i++)(f[x][i]+=f[x][i-1])%=p;
	
}

void change(int L,int val,int R){
	if(val==v[L])return;
	int upd=val-v[L];v[L]=val;
	if(id[L]==id[R]){
		for(rt i=L;i<=R;i++)s[i]+=upd;
		return;
	}
	for(rt i=L;i<(id[L]+1)*blo;i++)s[i]+=upd;build(id[L]);
	for(rt i=id[L]+1;;i++){
		if(i==id[R]){
			for(rt j=i*blo;j<=R;j++)s[j]+=upd;
			return;
		}
		tag[i]+=upd;
	}
}
 
int query(int x,int val){
	val-=tag[x];
	if(val>maxs[x])return 0;
	if(val<=0)return f[x][maxs[x]];
	return (f[x][maxs[x]]-f[x][val-1])%p;
}

int main(){
	fio;
	n=r;k=r;blo=(int)sqrt(n);
	for(rt i=0;i<n;i++)id[i]=i/blo;
	for(rt i=1;i<=n;i++)now[i]=la[i]=-1;
	for(rt i=0;i<n;i++){
		x=r;if(i)s[i]=s[i-1]+tag[(i-1)/blo];
		if(now[x]!=-1)change(now[x],-1,i);
		if(la[x]!=-1)change(la[x],0,i);
		la[x]=now[x];now[x]=i;v[i]=1;s[i]++;
		for(rt j=0;j<=i;j+=blo)(dp[i]+=query(id[j],s[i]+tag[id[i]]-k))%=p;
		for(rt j=i/blo*blo;j<i;j++)if(s[j]+tag[id[j]]>=s[i]+tag[id[i]]-k)(dp[i]+=dp[j])%=p;
		if(s[i]<=k)dp[i]++;
		if((i+1)%blo==0)build(id[i]);
	}
	cout<<(dp[n-1]%p+p)%p;
}