#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

const double eps=1e-10;
double ans;
LL n,a[N],t[N],T,p[N],mx[N],mn[N];

bool cmp1(LL x,LL y){
	return a[x]*t[y]>a[y]*t[x];
}

bool cmp2(LL x,LL y){
	return a[x]<a[y];
}

bool check(double x){
	double now=0;
	for (LL i=1;i<=n;++i){
		LL j=i;
		for (;j<=n&&a[p[i]]==a[p[j]];++j);
		--j;
		double tmp=1e10;
		for (LL k=i;k<=j;++k){
			tmp=min(tmp,a[p[k]]*(1-x*mx[p[k]]/T));
		}
		if (tmp<now) return 0;
		for (LL k=i;k<=j;++k){
			now=max(now,a[p[k]]*(1-x*mn[p[k]]/T));
		}
		i=j;
	}
	return 1;
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	for (LL i=1;i<=n;++i){scanf("%lld",t+i); T+=t[i];}
	for (LL i=1;i<=n;++i) p[i]=i;
	sort(p+1,p+n+1,cmp1);
	for (LL i=1,sum=0;i<=n;++i){
		LL j=i;
		for (;j<=n&&a[p[i]]*t[p[j]]==a[p[j]]*t[p[i]];++j);
		--j;
		LL tmp=0;
		for (LL k=i;k<=j;++k) tmp+=t[p[k]];
		for (LL k=i;k<=j;++k){
			mn[p[k]]=sum+t[p[k]];
			mx[p[k]]=sum+tmp;
		}
		sum+=tmp;
		i=j;
	}
	sort(p+1,p+n+1,cmp2);
	double l=0,r=1;
	while (l+eps<r){
		double mid=(l+r)/2;
		if (check(mid)) l=ans=mid;
		else r=mid;
	}
	printf("%.10f\n",ans);
	
	return 0;
}