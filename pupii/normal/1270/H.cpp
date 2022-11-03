#include<bits/stdc++.h>
#define inf 1000000000
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct qwq{int a,b;}seg[4000010];
qwq operator+(const qwq&a,const qwq&b){
	if(a.a<b.a)return a;
	if(a.a>b.a)return b;
	return{a.a,a.b+b.b};
}
int tag[4000010];
int N=1000000;
std::set<int>st;
#define mid ((l+r)>>1)
void build(int x,int l,int r){
	seg[x]={inf,r-l+1};if(l==r)return;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
}
void upd(int x,int d){tag[x]+=d,seg[x].a+=d;}
void down(int x){if(tag[x])upd(x<<1,tag[x]),upd(x<<1|1,tag[x]),tag[x]=0;}
void update(int x,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R)return upd(x,d);
	down(x);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
int query(int x,int l,int r,int p){
	if(l==r)return seg[x].a;
	down(x);
	if(p<=mid)return query(x<<1,l,mid,p);
	else return query(x<<1|1,mid+1,r,p);
}
#undef mid
int n,q,a[500010];
void Update(int pos,int o){
	if(!a[pos])return;
	static qwq b[5];int m=0,l=pos-(pos>1),r=pos+1;
	for(int i=pos-1;i<=pos+1;++i)if(a[i])b[++m]={a[i],i};
	b[++m]={0,-1};
	std::sort(b+1,b+m+1,[](const qwq&a,const qwq&b){return a.a>b.a;});
	for(int i=1,p,c=0;i<m;++i){
		p=b[i].b;
		if(p>l)c+=1-2*(a[p-1]>a[p]);
		if(p<r)c+=1-2*(a[p+1]>a[p]);
		if(c)update(1,1,N,b[i+1].a+1,b[i].a,c*o);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),q=gi();if(n==1){while(q--)puts("1");return 0;}
	build(1,1,N);
	for(int i=1;i<=n;++i)a[i]=gi(),update(1,1,N,a[i],a[i],-inf),st.insert(a[i]);
	update(1,1,N,1,a[n],1);
	for(int i=1;i<n;++i)
		if(a[i]<a[i+1])update(1,1,N,a[i]+1,a[i+1],1);
		else update(1,1,N,a[i+1]+1,a[i],1);
	for(int i=1;i<=q;++i){
		int p=gi(),x=gi();
		Update(p,-1);update(1,1,N,a[p],a[p],inf);
		st.erase(a[p]);
		a[p]=x;update(1,1,N,x,x,-inf);
		st.insert(x);
		Update(p,1);
		printf("%d\n",seg[1].b);
	}
	return 0;
}