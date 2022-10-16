#include<bits/stdc++.h>
using namespace std;
const int maxn=150010;
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
int n,q,p,cov[maxn*4],a[maxn];
struct fuck{
	int x[5],cnt[5];
	fuck(){MEM(x,0);MEM(cnt,0);}
	void insert(int x_,int cnt_){
		FOR(i,0,p-1) if(x_==x[i]) return void(cnt[i]+=cnt_);
		FOR(i,0,p-1) if(!x[i]) return void((x[i]=x_,cnt[i]=cnt_));
		int mn=0;
		FOR(i,1,p-1) if(x[i] && cnt[i]<cnt[mn]) mn=i;
		if(cnt_<cnt[mn]) FOR(i,0,p-1) cnt[i]-=cnt_;
		else{
			int tmp=cnt[mn];
			x[mn]=x_;cnt[mn]=cnt_;
			FOR(i,0,p-1) cnt[i]-=tmp;
		}
	}
	fuck operator+(fuck f)const{
		fuck ans=*this;
		FOR(i,0,p-1) if(f.x[i]) ans.insert(f.x[i],f.cnt[i]);
		return ans;
	}
}seg[maxn*4];
inline void cover(int o,int l,int r,int v){
	FOR(i,0,p-1) seg[o].x[i]=seg[o].cnt[i]=0;
	seg[o].x[0]=v;seg[o].cnt[0]=r-l+1;
	cov[o]=v;
}
inline void pushdown(int o,int l,int r){
	if(cov[o]){
		int mid=(l+r)>>1;
		cover(lson,cov[o]);
		cover(rson,cov[o]);
		cov[o]=0;
	}
}
void build(int o,int l,int r){
	if(l==r) return void((seg[o].x[0]=a[l],seg[o].cnt[0]=1));
	int mid=(l+r)>>1;
	build(lson);build(rson);
	seg[o]=seg[o<<1]+seg[o<<1|1];
//	printf("[%d,%d]:\n",l,r);
//	FOR(i,0,p-1) printf("%d %d\n",seg[o].x[i],seg[o].cnt[i]);
}
void update(int o,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr) return cover(o,l,r,v);
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
fuck query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg[o];
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	return query(lson,ql,qr)+query(rson,ql,qr);
}
int main(){
	n=read();q=read();p=100/read();
	FOR(i,1,n) a[i]=read();
	build(1,1,n);
	while(q--){
		int op=read(),x=read(),y=read();
		if(op==1) update(1,1,n,x,y,read());
		else{
			fuck ans=query(1,1,n,x,y);
			printf("%d ",p);
			FOR(i,0,p-1) printf("%d ",ans.x[i]);
			puts("");
		}
	}
}