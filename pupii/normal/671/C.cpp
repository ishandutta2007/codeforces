#include<bits/stdc++.h>
#define vd void
#define ll long long
int gi(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[200010],p[200010],s[200010];
ll QAQ[200010],tag[800010],sum[800010],mx[800010],mn[800010];
#define mid ((l+r)>>1)
vd Upd(int x,int l,int r,int d){tag[x]=d,sum[x]=1ll*(r-l+1)*d,mx[x]=d,mn[x]=d;}
vd down(int x,int l,int r){if(tag[x])Upd(x<<1,l,mid,tag[x]),Upd(x<<1|1,mid+1,r,tag[x]),tag[x]=0;}
bool update(int x,int l,int r,const int&L,const int&R,const int&d){
	if(l^r)down(x,l,r);
	bool ret=0;
	if(L<=l&&r<=R){
		if(mn[x]>=d)return 0;
		if(mx[x]<=d)return Upd(x,l,r,d),1;
		if(update(x<<1,l,mid,L,R,d))ret=update(x<<1|1,mid+1,r,L,R,d);
	}else{
		if(L<=mid)update(x<<1,l,mid,L,R,d);
		if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
	}
	sum[x]=sum[x<<1]+sum[x<<1|1];
	mn[x]=std::min(mn[x<<1],mn[x<<1|1]);
	mx[x]=std::max(mx[x<<1],mx[x<<1|1]);
	return ret;
}
vd build(int x,int l,int r){
	if(l==r){sum[x]=mx[x]=mn[x]=l;return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	sum[x]=sum[x<<1]+sum[x<<1|1];
	mn[x]=l;mx[x]=r;
}
#undef mid
int main(){
	int n=gi(),M=200000;
	for(int i=1;i<=n;++i)a[i]=gi(),s[a[i]]=i;
	build(1,1,n);
	QAQ[M]=1ll*(n+1)*n/2;
	for(int i=M;i;--i){
		int m=0;
		for(int d=i;d<=M;d+=i)if(s[d])p[++m]=s[d];
		if(m<2){QAQ[i-1]=QAQ[i];continue;}
		int p1=1e9,p2=1e9,p3=0,p4=0;
		for(int i=1;i<=m;++i){
			if(p[i]>p3)p4=p3,p3=p[i];
			else p4=std::max(p4,p[i]);
			if(p[i]<p1)p2=p1,p1=p[i];
			else p2=std::min(p2,p[i]);
		}
		update(1,1,n,1,p1,p4);
		update(1,1,n,p1+1,p2,p3);
		if(p2!=n)update(1,1,n,p2+1,n,n+1);
		QAQ[i-1]=1ll*(n+1)*n-sum[1];
	}
	ll ans=0;
	for(int i=1;i<=M;++i)ans+=1ll*i*(QAQ[i]-QAQ[i-1]);
	printf("%lld\n",ans);
	return 0;
}