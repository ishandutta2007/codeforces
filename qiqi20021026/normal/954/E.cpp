#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define LD double
#define eps 1e-8
#define N 300000

LL n,m,sum;
LD ans,mul[N];
struct node{
	LL x,y;
	bool operator < (const node p) const{
		return y<p.y;
	}
}a[N];

int main(){
	scanf("%lld%lld",&n,&m);
	for (LL i=1;i<=n;++i){
		scanf("%lld",&a[i].x);
		sum+=a[i].x;
	}
	for (LL i=1;i<=n;++i)
		scanf("%lld",&a[i].y);
	sort(a+1,a+n+1);
	for (LL i=1;i<=n;++i) mul[i]=(LD)a[i].x*a[i].y;
	LD l=0,r=sum;
	while (r-l>eps){
		LD mid=(l+r)/2,tmp=mid,mn=0,mx=0;
		for (LL i=1;i<=n;++i)
			if (tmp>a[i].x){
				tmp-=a[i].x;
				mn+=mul[i];
			}
			else{
				mn+=a[i].y*tmp;
				break;
			}
		tmp=mid;
		for (LL i=n;i>=1;--i)
			if (tmp>a[i].x){
				tmp-=a[i].x;
				mx+=mul[i];
			}
			else{
				mx+=a[i].y*tmp;
				break;
			}
		if (mn-m*mid<eps&&mx-m*mid>-eps){
			l=ans=mid;
		}
		else r=mid;
	}
	printf("%.8f\n",ans);
	
	return 0;
}