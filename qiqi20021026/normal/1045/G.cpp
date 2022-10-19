#include<bits/stdc++.h>

using namespace std;

#define N 120000
#define M 1000000000

int n,m,cnt,xb,f[N],rt[N],s[N*30],ls[N*30],rs[N*30];
long long ans;
struct node{int x,y,z,u,v;}a[N],b[N],c[N];

bool cmpx(node p,node q){return p.x<q.x;}

bool cmpu(node p,node q){return p.u<q.u;}

bool cmpv(node p,node q){return p.v<q.v;}

void mdf(int &x,int l,int r,int k){
	if (!x) x=++cnt; ++s[x];
	if (l==r) return;
	int mid=(l+r)>>1;
	if (k<=mid) mdf(ls[x],l,mid,k);
	else mdf(rs[x],mid+1,r,k);
}

int qry(int x,int l,int r,int L,int R){
	if (!x||L>R||R<0||L>M) return 0;
	if (l>=L&&r<=R) return s[x];
	int mid=(l+r)>>1,ret=0;
	if (L<=mid) ret+=qry(ls[x],l,mid,L,R);
	if (R>mid) ret+=qry(rs[x],mid+1,r,L,R);
	return ret;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].u=a[i].x-a[i].y; a[i].v=a[i].x+a[i].y;
		b[i]=c[i]=a[i];
		f[i]=a[i].z;
	}
	sort(f+1,f+n+1);
	f[xb=1]=f[1];
	for (int i=2;i<=n;++i) if (f[i]!=f[xb]) f[++xb]=f[i];
	sort(a+1,a+n+1,cmpx);
	sort(b+1,b+n+1,cmpu);
	sort(c+1,c+n+1,cmpv);
	for (int i=1,j=1;i<=n;++i){
		for (;j<=n&&b[j].u<=a[i].x;++j){
			int x=b[j].x,z=lower_bound(f+1,f+xb+1,b[j].z)-f;
			mdf(rt[z],0,M,x);
		}
		int k=lower_bound(f+1,f+xb+1,a[i].z-m)-f; 
		for (k=max(k,1);k<=xb&&f[k]<=a[i].z+m;++k)
			ans+=qry(rt[k],0,M,a[i].x,a[i].x+a[i].y);
	}
	cnt=0; memset(s,0,sizeof s); memset(ls,0,sizeof ls); memset(rs,0,sizeof rs); memset(rt,0,sizeof rt);
	for (int i=n,j=n;i;--i){
		for (;j&&c[j].v>=a[i].x;--j){
			int x=c[j].x,z=lower_bound(f+1,f+xb+1,c[j].z)-f;
			mdf(rt[z],0,M,x);
		}
		int k=lower_bound(f+1,f+xb+1,a[i].z-m)-f; 
		for (k=max(k,1);k<=xb&&f[k]<=a[i].z+m;++k)
			ans+=qry(rt[k],0,M,a[i].x-a[i].y,a[i].x-1);
	}
	printf("%lld\n",(ans-n)/2);
	
	return 0;
}