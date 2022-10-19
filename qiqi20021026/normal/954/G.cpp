#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define INF 0x3f3f3f3f3f3f3f3fLL
#define N 1200000

LL n,m,p,a[N],b[N],ans;

bool chk(LL mid,LL k){
	memcpy(b,a,sizeof b);
	LL tmp=0;
	LL l=-m,r=m;
	for (LL i=l;i<=r;++i)
		if (i>0) tmp+=b[i];
	for (LL i=1;i<=n;++i){
		++l; ++r;
		if (l-1>0) tmp-=b[l-1];
		if (r<=n) tmp+=b[r];
		if (tmp<mid){
			b[r]+=mid-tmp;
			k-=mid-tmp;
			tmp=mid;
			if (k<0) return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	for (LL i=1;i<=n;++i) scanf("%lld",&a[i]);
	LL l=0,r=INF;
	while (l<=r){
		LL mid=(l+r)>>1;
		if (chk(mid,p)){l=mid+1; ans=mid;}
		else r=mid-1;
	}
	printf("%lld\n",ans);
	
	return 0;
}