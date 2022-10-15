
// Problem : D. Binary String To Subsequences
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int N=2e5+5;
int n,m,mm,l,i,p[N],a[N],x;bool f;
ll ans;
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
int main(){
	for (n=read(),i=1;i<=n;i++) p[i]=read();
	for (m=read(),i=1;i<=m;i++) a[read()]++;
	mm=m;m+=a[1]+a[n];a[1]<<=1;a[n]<<=1;
	for (i=1;i<n&&a[i]==a[i+1];i++);
	if (i==n){
		for (i=2;i<n;i++) if (p[i]-p[i-1]!=p[i+1]-p[i]) break;
		if (i<n) puts("-1"); else printf("%I64d",(ll)(mm-1)*(p[2]-p[1]));
		return 0;
	}
	if (a[1]>a[2]) a[1]--,m--;
	if (a[n]>a[n-1]) a[n]--,m--;
	p[0]=p[1];p[n+1]=p[n];l=p[n]-p[1];
	if (a[1]>a[n]){
		for (x=1;a[x]==a[x+1];x++);
		if (m<=x){printf("%d",p[x]-p[x-m+1]);return 0;}
		m-=x;ans=p[x]-p[1];if (!((m/n)&1)) f=1;
	}
	else{
		if (a[1]==a[n]) for (x=n;a[x]<=a[x-1];x--);
		else for (x=n;a[x]==a[x-1];x--);
		if (m<=n-x+1){printf("%d",p[x+m-1]-p[x]);return 0;}
		m-=n-x+1;ans=p[n]-p[x];if ((m/n)&1) f=1;
	}
	ans+=(ll)m/n*l;m%=n;
	if (f) printf("%I64d",ans+p[m]-p[1]);
	else printf("%I64d",ans+p[n]-p[n-m+1]);
}