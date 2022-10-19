#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 800000
#define ls (x<<1)
#define rs (x<<1|1)
#define INF 0x3f3f3f3f3f3f3f3fLL

LL n,m,op,l,r,x,ans,a[N],d[N],seg[N];
set<LL> se;

void renew(LL x,LL l,LL r,LL k){
	if (l==r){
		set<LL>::iterator j=se.find(l);
		if (j!=se.end()) se.erase(j);
		if (d[l-1]<=0&&d[l]>=0){seg[x]=INF; return;}
		if (d[l-1]>0&&d[l]<0){
			seg[x]=-INF; se.insert(l);
			return;
		}
		if (d[l-1]<=0) seg[x]=d[r];
		else seg[x]=-d[l-1];
		return;
	}
	LL mid=(l+r)>>1;
	if (k<=mid) renew(ls,l,mid,k);
	else renew(rs,mid+1,r,k);
	seg[x]=max(seg[ls],seg[rs]);
}

LL qry(LL x,LL l,LL r,LL L,LL R){
	if (l>=L&&r<=R) return seg[x];
	LL mid=(l+r)>>1,tmp=-INF;
	if (L<=mid) tmp=max(tmp,qry(ls,l,mid,L,R));
	if (R>mid) tmp=max(tmp,qry(rs,mid+1,r,L,R));
	return tmp;
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i) scanf("%lld",&a[i]);
	for (LL i=1;i<n;++i){d[i]=a[i]-a[i+1]; ans+=abs(d[i]);}
	for (LL i=1;i<=n;++i) renew(1,1,n,i);
	scanf("%lld",&m);
	for (LL i=1;i<=m;++i){
		scanf("%lld%lld%lld%lld",&op,&l,&r,&x);
		if (op==1){
			LL mx=0;
			if (l==1){mx=max(mx,abs(d[1]+x)); ++l;}
			if (r==n){mx=max(mx,abs(d[n-1]-x)); --r;}
			LL tmp=qry(1,1,n,l,r);
			if (tmp>=INF) mx=ans+x*2;
			else{
				if (tmp>-INF) mx=ans;
				mx=max(mx,ans+(x+tmp)*2);
				set<LL>::iterator j=se.lower_bound(l);
				if (j!=se.end()&&*j<=r)
					mx=max(mx,ans-abs(d[*j-1])-abs(d[*j])+abs(d[*j-1]-x)+abs(d[*j]+x));
			}
			printf("%lld\n",mx);
		}
		if (op==2){
			if (l>1){
				ans-=abs(d[l-1]);
				d[l-1]-=x; ans+=abs(d[l-1]);
				renew(1,1,n,l-1);
				renew(1,1,n,l);
			}
			if (r<n){
				ans-=abs(d[r]);
				d[r]+=x; ans+=abs(d[r]);
				renew(1,1,n,r);
				renew(1,1,n,r+1);
			}
		}
	}		
	
	return 0;
}