#include<bits/stdc++.h>
using namespace std;
const int maxn=200020,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,k,q,a[maxn][5],b[5];
struct node{
	int mx[32];
	node operator+(const node &nd)const{
		node ans;
		FOR(i,0,(1<<k)-1) ans.mx[i]=max(mx[i],nd.mx[i]);
		return ans;
	}
}seg[maxn<<2];
void build(int o,int l,int r){
	if(l==r){
		FOR(i,0,(1<<k)-1) FOR(j,0,k-1){
			if((i>>j)&1) seg[o].mx[i]+=a[l][j];
			else seg[o].mx[i]-=a[l][j];
		}
		return;
	}
	int mid=(l+r)>>1;
	build(lson);build(rson);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
void update(int o,int l,int r,int p,int b[]){
	if(l==r){
		FOR(i,0,(1<<k)-1){
			seg[o].mx[i]=0;
			FOR(j,0,k-1){
				if((i>>j)&1) seg[o].mx[i]+=b[j];
				else seg[o].mx[i]-=b[j];
			}
		}
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p,b);
	else update(rson,p,b);
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
	n=read();k=read();
	FOR(i,1,n) FOR(j,0,k-1) a[i][j]=read();
	build(1,1,n);
	q=read();
	while(q--){
		int op=read();
		if(op==1){
			int id=read();
			FOR(i,0,k-1) b[i]=read();
			update(1,1,n,id,b);
		}
		else{
			int l=read(),r=read(),s=INT_MIN;
			node ans=query(1,1,n,l,r);
			FOR(i,0,(1<<k)-1) s=max(s,ans.mx[i]+ans.mx[(1<<k)-1-i]);
			printf("%d\n",s);
		}
	}
}