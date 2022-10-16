#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=888888;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,k;
char s[maxn];
ll seg[maxn],seg2[maxn],f[maxn];
void pushup(int o){
	seg[o]=min(seg[o<<1],seg[o<<1|1]);
	seg2[o]=min(seg2[o<<1],seg2[o<<1|1]);
}
void build(int o,int l,int r){
	seg[o]=seg2[o]=1e18;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(lson);build(rson);
}
void update(int o,int l,int r,int p,ll v){
	if(l==r) return void(seg[o]=v);
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p,v);
	if(mid<p) update(rson,p,v);
	pushup(o);
}
void update2(int o,int l,int r,int p,ll v){
	if(l==r) return void(seg2[o]=v);
	int mid=(l+r)>>1;
	if(mid>=p) update2(lson,p,v);
	if(mid<p) update2(rson,p,v);
	pushup(o);
}
ll query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg[o];
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	return min(query(lson,ql,qr),query(rson,ql,qr));
}
ll query2(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg2[o];
	int mid=(l+r)>>1;
	if(mid<ql) return query2(rson,ql,qr);
	if(mid>=qr) return query2(lson,ql,qr);
	return min(query2(lson,ql,qr),query2(rson,ql,qr));
}
int main(){
	n=read();k=read();
	scanf("%s",s+1);
	MEM(f,0x3f);
	f[0]=0;
	f[1]=1;
	build(1,0,n);
	if(s[1]=='1') update(1,0,n,1,1);
	update2(1,0,n,0,0);update2(1,0,n,1,1);
	FOR(i,2,n){
		if(s[i]=='1') update(1,0,n,i,query2(1,0,n,max(i-k-1,0),i-1)+i);
		f[i]=min(f[i-1]+i,query(1,0,n,max(i-k,1),i));
		update2(1,0,n,i,f[i]);
//		printf("f[%d]=%lld\n",i,f[i]);
	}
	printf("%lld\n",f[n]);
}