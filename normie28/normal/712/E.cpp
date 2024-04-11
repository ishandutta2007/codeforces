
// Problem : E. Memory and Casinos
// Contest : Codeforces - Codeforces Round #370 (Div. 2)
// URL : https://codeforces.com/problemset/problem/712/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
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
#define pdd pair<double,double>
#define mp make_pair
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
struct node{
	double x,y;
}t[300000];
 
int n,q;
int a[100005],b[100005];
 
void update(int id){
	t[id].x=t[id<<1].x*t[id<<1|1].x/(1-(1-t[id<<1|1].x)*t[id<<1].y);
	t[id].y=t[id<<1|1].y+(1-t[id<<1|1].y)*t[id<<1].y*t[id<<1|1].x/(1-(1-t[id<<1|1].x)*t[id<<1].y);
}
 
void build(int id,int l,int r){
	if(l==r) return(void)(t[id].x=t[id].y=1.0*a[l]/b[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}
 
void change(int id,int l,int r,int p,double c){
	if(l==p&&r==p) return (void)(t[id].x=t[id].y=c);
	int mid=(l+r)/2;
	if(p<=mid) change(id<<1,l,mid,p,c);
	else change(id<<1|1,mid+1,r,p,c);
	update(id);
}
 
pdd query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return mp(t[id].x,t[id].y);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	pdd lson=query(id<<1,l,mid,ql,mid),rson=query(id<<1|1,mid+1,r,mid+1,qr),ans;
	ans.fi=lson.fi*rson.fi/(1-(1-rson.fi)*lson.se);
	ans.se=rson.se+(1-rson.se)*lson.se*rson.fi/(1-(1-rson.fi)*lson.se);
	return ans;
}
 
int main(){
	fio;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	build(1,1,n);
	int opt,x,y,z;
	while(q--){
		cin>>opt>>x>>y;
		if(opt==1) {cin>>z; change(1,1,n,x,1.0*y/z);}
		else cout<<fixed<<setprecision(10)<<query(1,1,n,x,y).fi<<endl;
	}
}