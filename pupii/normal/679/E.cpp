#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll p42[10];
ll nxt(ll x){return*std::lower_bound(p42+1,p42+10,x);}
ll t[100010];
#pragma pack(4)
struct data{ll rem,real;int l,r;}seg[400010];
data operator+(const data&a,const data&b){
	if(a.rem<b.rem)return a;
	if(a.rem>b.rem)return b;
	if(a.real==b.real&&a.r==b.l-1)return{a.rem,a.real,a.l,b.r};
	return a;
}
#define mid ((l+r)>>1)
ll tag[400010],Tag[400010];
void build(int x,int l,int r){
	if(l==r){seg[x]={nxt(t[l])-t[l],t[l],l,l};return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
void upd(int x,ll d){seg[x].rem-=d,seg[x].real+=d,tag[x]+=d;}
void Upd(int x,int l,int r,ll d){seg[x].rem=nxt(d)-d,seg[x].real=d,seg[x].l=l,seg[x].r=r,Tag[x]=d,tag[x]=0;}
void down(int x,int l,int r){
	if(Tag[x])Upd(x<<1,l,mid,Tag[x]),Upd(x<<1|1,mid+1,r,Tag[x]),Tag[x]=0;
	if(tag[x])upd(x<<1,tag[x]),upd(x<<1|1,tag[x]),tag[x]=0;
}
ll query(int x,int l,int r,int p){
	if(l==r)return seg[x].real;
	down(x,l,r);
	if(p<=mid)return query(x<<1,l,mid,p);
	else return query(x<<1|1,mid+1,r,p);
}
void update2(int x,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R)return Upd(x,l,r,d);
	down(x,l,r);
	if(L<=mid)update2(x<<1,l,mid,L,R,d);
	if(mid<R)update2(x<<1|1,mid+1,r,L,R,d);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
void update3(int x,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R)return upd(x,d);
	down(x,l,r);
	if(L<=mid)update3(x<<1,l,mid,L,R,d);
	if(mid<R)update3(x<<1|1,mid+1,r,L,R,d);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
void update4(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R)return Upd(x,l,r,seg[x].real);
	down(x,l,r);
	if(L<=mid)update4(x<<1,l,mid,L,R);
	if(mid<R)update4(x<<1|1,mid+1,r,L,R);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
#undef mid
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	p42[0]=1;for(int i=1;i<10;++i)p42[i]=42*p42[i-1];
	int n=gi(),q=gi();
	for(int i=1;i<=n;++i)t[i]=gi();
	build(1,1,n);
	int o,l,r,x;
	while(q--){
		o=gi();
		if(o==1)printf("%lld\n",query(1,1,n,gi()));
		else if(o==2)l=gi(),r=gi(),x=gi(),update2(1,1,n,l,r,x);
		else{
			l=gi(),r=gi(),x=gi();
			bool f;
			do{
				update3(1,1,n,l,r,x);
				f=0;
				while(1){
					data o=seg[1];
					if(o.rem>=0){f=!o.rem;break;}
					if(o.rem<0)update4(1,1,n,o.l,o.r);
				}
			}while(f);
		}
		//for(int i=1;i<=n;++i)printf("%lld ",query(1,1,n,i));puts("");
	}
	return 0;
}