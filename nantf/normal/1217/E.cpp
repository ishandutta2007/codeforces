#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,pw[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
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
int n,m,a[maxn];
struct node{
	ll ans,mn[9];
	node operator+(const node &nd)const{
		node s;
		s.ans=min(ans,nd.ans);
		FOR(i,0,8) s.ans=min(s.ans,mn[i]+nd.mn[i]),s.mn[i]=min(mn[i],nd.mn[i]);
		return s;
	}
}seg[maxn*4];
inline int get(int x,int id){return x/pw[id]%10;}
void build(int o,int l,int r){
	if(l==r){
		seg[o].ans=1e18;
		FOR(i,0,8) seg[o].mn[i]=get(a[l],i)?a[l]:1e18;
		return;
	}
	int mid=(l+r)>>1;
	build(lson);build(rson);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
void update(int o,int l,int r,int p,int v){
	if(l==r){
		seg[o].ans=1e18;
		FOR(i,0,8) seg[o].mn[i]=get(v,i)?v:1e18;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p,v);
	else update(rson,p,v);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
node query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg[o];
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	return query(lson,ql,qr)+query(rson,ql,qr);
}
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	build(1,1,n);
	while(m--){
		int op=read(),x=read(),y=read();
		if(op==1) update(1,1,n,x,y);
		else{
			ll ans=query(1,1,n,x,y).ans;
			printf("%lld\n",ans>=2e9?-1ll:ans);
		}
	}
}