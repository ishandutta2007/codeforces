
// Problem : C. Alyona and towers
// Contest : Codeforces - Codeforces Round #381 (Div. 1)
// URL : https://codeforces.com/problemset/problem/739/C
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
#pragma GCC optimize("O3,unroll-loops")
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
typedef long long LL;
#define RI register int
//---------END-------//
const int N=300005;
int n,m;LL a[N],d[N];
struct node{int lud,ld,rud,ru,mx;}tr[N<<2];
 
void up(int i,int s,int t) {
	int l=i<<1,r=(i<<1)|1,mid=(s+t)>>1;
	tr[i].mx=max(tr[l].mx,tr[r].mx);
	tr[i].mx=max(tr[i].mx,max(tr[l].rud+tr[r].ld,tr[l].ru+tr[r].lud));
	tr[i].lud=tr[l].lud,tr[i].ld=tr[l].ld;
	tr[i].rud=tr[r].rud,tr[i].ru=tr[r].ru;
	if(tr[l].lud==mid-s+1) tr[i].lud=max(tr[i].lud,tr[l].lud+tr[r].ld);
	if(tr[l].ld==mid-s+1) tr[i].ld=max(tr[i].ld,tr[l].ld+tr[r].ld);
	if(tr[r].rud==t-mid) tr[i].rud=max(tr[i].rud,tr[r].rud+tr[l].ru);
	if(tr[r].ru==t-mid) tr[i].ru=max(tr[i].ru,tr[r].ru+tr[l].ru);
	if(tr[l].ru==mid-s+1) tr[i].lud=max(tr[i].lud,tr[l].ru+tr[r].lud);
	if(tr[r].ld==t-mid) tr[i].rud=max(tr[i].rud,tr[r].ld+tr[l].rud);
}
void QAQ(int i,LL v) {
	if(v==0LL) tr[i].lud=tr[i].ld=tr[i].rud=tr[i].ru=tr[i].mx=0;
	else if(v>0LL)
		tr[i].lud=tr[i].rud=tr[i].ru=tr[i].mx=1,tr[i].ld=0;
	else tr[i].lud=tr[i].ld=tr[i].rud=tr[i].mx=1,tr[i].ru=0;
}
void build(int s,int t,int i) {
	if(s==t) {QAQ(i,d[s]);return;}
	int mid=(s+t)>>1;
	build(s,mid,i<<1),build(mid+1,t,(i<<1)|1);
	up(i,s,t);
}
void chan(int x,int s,int t,int i,int v) {
	if(s==t) {d[s]+=(LL)v,QAQ(i,d[s]);return;}
	int mid=(s+t)>>1;
	if(x<=mid) chan(x,s,mid,i<<1,v);
	else chan(x,mid+1,t,(i<<1)|1,v);
	up(i,s,t);
}
int main()
{
	fio;
	int l,r,v;
	cin>>n;
	for(RI i=1;i<=n;++i) cin>>a[i];
	if(n==1) {
		cin>>m; while(m--) cout<<1<<endl;
	}
	else
	{
	for(RI i=1;i<n;++i) d[i]=a[i+1]-a[i];
	build(1,n-1,1);
	cin>>m;
	while(m--) {
		cin>>l>>r>>v;
		if(l!=1) chan(l-1,1,n-1,1,v);
		if(r!=n) chan(r,1,n-1,1,-v);
		cout<<tr[1].mx+1<<endl;
	}
	}
}