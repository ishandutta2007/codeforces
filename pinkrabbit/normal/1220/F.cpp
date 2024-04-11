#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 400005
#define MS 1048576
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,Ans,Ansi;
int a[MN],b[MN],c[MN];
int lb[MN],rb[MN],stk[MN],tp;
int faz[MN],lc[MN],rc[MN];
int ldf[MN],rdf[MN];
void bbb(int u,int fz){
	c[u]=c[fz]+1;
	ldf[u]=rdf[u]=u;
	if(lc[u])bbb(lc[u],u),ldf[u]=ldf[lc[u]];
	if(rc[u])bbb(rc[u],u),rdf[u]=rdf[rc[u]];
}
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
#define ls li,l,mid
#define rs ri,mid+1,r
#define rt 1,1,n+n-1
int mx[MS],tg[MS];
inline void P(int i,int x){mx[i]+=x,tg[i]+=x;}
inline void pd(int i){if(tg[i])P(li,tg[i]),P(ri,tg[i]),tg[i]=0;}
void build(int i,int l,int r){
	if(l==r){mx[i]=c[l];return;}
	build(ls),build(rs);
	mx[i]=max(mx[li],mx[ri]);
}
void mdf(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b)return P(i,x);
	pd(i);
	mdf(ls,a,b,x),mdf(rs,a,b,x);
	mx[i]=max(mx[li],mx[ri]);
}
int qur(int i,int l,int r,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return mx[i];
	pd(i);
	return max(qur(ls,a,b),qur(rs,a,b));
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),b[i]=a[i];
	int pos=min_element(a+1,a+n+1)-a;
	F(i,1,n)a[i]=b[(pos+i-1)%n+1];
	F(i,1,n)a[n+i]=a[i];
//	F(i,1,n)printf("%d%c",a[i]," \n"[i==n]);
	stk[tp=1]=0;
	F(i,1,n){
		while(tp&&a[stk[tp]]>a[i])rb[stk[tp--]]=i;
		lb[i]=stk[tp],stk[++tp]=i;
	}while(tp)rb[stk[tp--]]=n+1;
	F(i,1,n-1){
		if(a[lb[i]]>a[rb[i]])faz[i]=lb[i],rc[lb[i]]=i;
		else faz[i]=rb[i],lc[rb[i]]=i;
	}
	bbb(n,0),Ans=*max_element(c+1,c+n+1),Ansi=pos%n;
	build(rt);
	stk[tp=1]=n;
	F(i,1,n-1){
		mdf(rt,i+1,rdf[i],-1);
		int x=0;
		while(tp&&a[stk[tp]]>a[i+n])x=stk[tp--];
		ldf[i+n]=x?ldf[x]:i+n;
		mdf(rt,ldf[i+n],i+n,1);
		mdf(rt,i+n,i+n,tp);
		stk[++tp]=i+n;
//		F(j,i+1,i+n)printf("%d%c",qur(rt,j,j)," \n"[j==i+n]);
		int now=qur(rt,i+1,i+n);
		if(Ans>now)Ans=now,Ansi=(pos+i)%n;
	}
	printf("%d %d\n",Ans,Ansi);
	return 0;
}