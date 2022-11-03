//YSZ BINIU
#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct data{
	int prex,pren,sufx,sufn,pred,sufd,d,sum,ans;
	data(){}
	data(int a,int b,int c,int D,int f,int h,int j,int k,int l){prex=a,pren=b,sufx=c,sufn=D,pred=f,sufd=h,d=j,sum=k,ans=l;}
}seg[800010],leafl(1,0,1,0,1,1,1,1,1),leafr(0,-1,0,-1,1,1,1,-1,1);
il data operator+(const data&a,const data&b){
	data c;
	c.prex=std::max(a.prex,a.sum+b.prex);
	c.sufx=std::max(b.sufx,b.sum+a.sufx);
	c.pren=std::min(a.pren,a.sum+b.pren);
	c.sufn=std::min(b.sufn,b.sum+a.sufn);
	c.d=std::max(b.d-a.sum,a.d+b.sum);
	c.pred=std::max(a.pred,std::max(b.pred-a.sum,a.d+b.prex));
	c.sufd=std::max(b.sufd,std::max(b.sum+a.sufd,b.d-a.sufn));
	c.sum=a.sum+b.sum;
	c.ans=std::max(std::max(a.ans,b.ans),std::max(b.pred-a.sufn,a.sufd+b.prex));
	return c;
}
char brace[200010];
#define mid ((l+r)>>1)
il vd build(int x,int l,int r){
	if(l==r){seg[x]=brace[l]=='('?leafl:leafr;return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
il vd update(int x,int l,int r,const int&p){
	if(l==r){seg[x]=brace[l]=='('?leafl:leafr;return;}
	if(p<=mid)update(x<<1,l,mid,p);
	else update(x<<1|1,mid+1,r,p);
	seg[x]=seg[x<<1]+seg[x<<1|1];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi()-1<<1,q=gi(),x,y;
	scanf("%s",brace+1);build(1,1,n);
	printf("%d\n",seg[1].ans);
	while(q--){
		x=gi(),y=gi(),std::swap(brace[x],brace[y]);
		update(1,1,n,x),update(1,1,n,y);
		printf("%d\n",seg[1].ans);
	}
	return 0;
}