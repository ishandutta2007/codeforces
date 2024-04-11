#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 120000
#define INF 0x3f3f3f3f3f3f3f3fLL

LL t,n,L[4],R[4],ans[4],a[N],b[N],c[N];

bool pd_odd(LL t){
	LL l=L[0]-t,r=R[0]+t;
	if (l%2==0) ++l;
	if (r%2==0) --r;
	l=(l-3)/2; r=(r-3)/2;
	if (l>r) return 0;
	LL suml=0,sumr=0;
	for (LL i=1;i<=3;++i){
		LL x=L[i]-t;
		if (x%2==0) ++x;
		x=(x-1)/2;
		LL y=R[i]+t;
		if (y%2==0) --y;
		y=(y-1)/2;
		if (x>y) return 0;
		suml+=x;
		sumr+=y;
	}
	if (suml<=r&&sumr>=l){
		for (LL i=1;i<=3;++i){
			LL x=L[i]-t;
			if (x%2==0) ++x;
			x=(x-1)/2;
			LL y=R[i]+t;
			if (y%2==0) --y;
			y=(y-1)/2;
			if (suml>=l) ans[i]=x*2+1;
			else{
				LL d=min(y-x,l-suml);
				suml+=d;
				ans[i]=(x+d)*2+1;
			}
		}
		return 1;
	}
	return 0;
}

bool pd_even(LL t){
	LL l=L[0]-t,r=R[0]+t;
	if (l%2==1) ++l;
	if (r%2==1) --r;
	l=l/2; r=r/2;
	if (l>r) return 0;
	LL suml=0,sumr=0;
	for (LL i=1;i<=3;++i){
		LL x=L[i]-t;
		if (x%2!=0) ++x;
		x=x/2;
		LL y=R[i]+t;
		if (y%2!=0) --y;
		y=y/2;
		if (x>y) return 0;
		suml+=x;
		sumr+=y;
	}
	if (suml<=r&&sumr>=l){
		for (LL i=1;i<=3;++i){
			LL x=L[i]-t;
			if (x%2!=0) ++x;
			x=x/2;
			LL y=R[i]+t;
			if (y%2!=0) --y;
			y=y/2;
			if (suml>=l) ans[i]=x*2;
			else{
				LL d=min(y-x,l-suml);
				suml+=d;
				ans[i]=(x+d)*2;
			}
		}
		return 1;
	}
	return 0;
}

int main(){
	scanf("%lld",&t);
	while (t--){
		scanf("%lld",&n);
		memset(L,0xcf,sizeof L);
		memset(R,0x3f,sizeof R);
		for (LL i=1;i<=n;++i){
			scanf("%lld%lld%lld",a+i,b+i,c+i);
			L[0]=max(L[0],a[i]+b[i]+c[i]);
			R[0]=min(R[0],a[i]+b[i]+c[i]);
			L[1]=max(L[1],-a[i]+b[i]+c[i]);
			R[1]=min(R[1],-a[i]+b[i]+c[i]);
			L[2]=max(L[2],a[i]-b[i]+c[i]);
			R[2]=min(R[2],a[i]-b[i]+c[i]);
			L[3]=max(L[3],a[i]+b[i]-c[i]);
			R[3]=min(R[3],a[i]+b[i]-c[i]);
		}
		LL l=0,r=INF;
		while (l<=r){
			LL mid=(l+r)>>1;
			if (pd_odd(mid)||pd_even(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("%lld %lld %lld\n",(ans[2]+ans[3])/2,(ans[1]+ans[3])/2,(ans[1]+ans[2])/2);
	}
	
	return 0;
}