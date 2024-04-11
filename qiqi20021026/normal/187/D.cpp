#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 300000
#define INF 0x3f3f3f3f3f3f3f3fLL

LL n,A,B,C,x,p,ans,rt,tot,a[N],b[N],c[N],f[N],suf[N],ls[N<<5],rs[N<<5],seg[N<<5];

void mdf(LL &x,LL l,LL r,LL t,LL k){
	if (!x){x=++tot; seg[x]=INF; ls[x]=rs[x]=0;}
	if (l==r){seg[x]=k; return;}
	LL mid=(l+r)>>1;
	if (t<=mid) mdf(ls[x],l,mid,t,k);
	else mdf(rs[x],mid+1,r,t,k);
	seg[x]=min(seg[ls[x]],seg[rs[x]]);
}

LL qry(LL x,LL l,LL r,LL L,LL R){
	if (!x) return INF;
	if (l>=L&&r<=R) return seg[x];
	LL mid=(l+r)>>1,ret=INF;
	if (L<=mid) ret=min(ret,qry(ls[x],l,mid,L,R));
	if (R>mid) ret=min(ret,qry(rs[x],mid+1,r,L,R));
	return ret;
}

int main(){
	scanf("%lld%lld%lld",&n,&A,&B); C=A+B;
	for (LL i=1;i<=n+1;++i){
		scanf("%lld",a+i);
		b[i]=b[i-1]+a[i];
		c[i]=b[i]%C;
	}
	seg[0]=INF;
	f[n]=a[n+1]; mdf(rt,0,C,c[n],n);
	for (LL i=n-1;i;--i){
		LL x=(-c[i]%C+C)%C;
		LL l=A*2+B-x,r=A*2+B*2-x-1,tmp=INF;
		if (l<=C&&l<=r) tmp=min(tmp,qry(rt,0,C,l,min(r,C)));
		l=A-x,r=A+B-x-1;
		if (r>=0&&r>=l) tmp=min(tmp,qry(rt,0,C,max(l,0LL),r));
		if (tmp>=INF) f[i]=b[n+1]-b[i];
		else{
			LL len=b[tmp]-b[i];
			len=(len+C-1)/C*C;
			f[i]=f[tmp]+len;
		}
		mdf(rt,0,C,c[i],i);
	}
	scanf("%lld",&p);
	while (p--){
		scanf("%lld",&x);
		ans=x/C*C; x%=C;
		LL l=A*2+B-x,r=A*2+B*2-x-1,tmp=INF;
		if (l<=C&&l<=r) tmp=min(tmp,qry(rt,0,C,l,min(r,C)));
		l=A-x,r=A+B-x-1;
		if (r>=0&&r>=l) tmp=min(tmp,qry(rt,0,C,max(l,0LL),r));
		if (tmp>=INF) ans+=x+b[n+1];
		else{
			LL len=x+b[tmp];
			len=(len+C-1)/C*C;
			ans+=f[tmp]+len;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}