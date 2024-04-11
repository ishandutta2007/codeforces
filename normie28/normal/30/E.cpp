
// Problem : E. Tricky and Clever Password
// Contest : Codeforces - Codeforces Beta Round #30 (Codeforces format)
// URL : https://codeforces.com/problemset/problem/30/E
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
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define Pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef vector<int> Vi;
//---------END-------//
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 203000;
int n,P[N],nxt[N],f[N],qz[N],pos[N];
char s[N],t[N];
inline void manacher() {
	int id=0;
	rep(i,1,n) {
		if (2*id-i>0) P[i]=min(P[2*id-i],id+P[id]-i);
		while (i-P[i]>0&&i+P[i]<=n&&s[i-P[i]]==s[i+P[i]]) ++P[i];
		if (i+P[i]>id+P[id]) id=i;
	}
}
inline void kmp(int n) { //t[1..n]
	for (int i=2,j=0; i<=n; i++) {
		while (j&&t[j+1]!=t[i]) j=nxt[j];
		if (t[j+1]==t[i]) j++;
		nxt[i]=j;
	}
}
int len,a[5],b[5],ans;
int main() { 
	scanf("%s",s+1); n=strlen(s+1); manacher();
	rep(i,1,n) t[i]=s[n-i+1]; t[n+1]='#'; int len=n+1;
	rep(i,1,n) t[++len]=s[i]; kmp(len);
	rep(i,1,n) f[i]=nxt[i+n+1];
	rep(i,1,n) {
		qz[i]=max(qz[i-1],f[i]);
		pos[i]=(qz[i]==f[i])?i:pos[i-1];
	}
	rep(i,1,n) {
		int p=pos[i-P[i]];
		if (n-f[p]+1<=i+P[i]-1) p-=(i+P[i]-1)-(n-f[p]+1)+1;
		if (!f[p]) {
			if ((i+P[i]-1)-(i-P[i]+1)+1>ans) {
				ans=(i+P[i]-1)-(i-P[i]+1)+1;
				len=1; a[1]=i-P[i]+1; b[1]=i+P[i]-1;
			}
		}
		else {
			if (f[p]*2+(i+P[i]-1)-(i-P[i]+1)+1>ans) {
				ans=f[p]*2+(i+P[i]-1)-(i-P[i]+1)+1;
				len=3; a[1]=p-f[p]+1; b[1]=p;
				a[2]=i-P[i]+1; b[2]=i+P[i]-1;
				a[3]=n-f[p]+1; b[3]=n;
			}
		}
	}
	printf("%d\n",len);
	rep(i,1,len) printf("%d %d\n",a[i],b[i]-a[i]+1);
}