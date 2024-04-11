#include<cstdio>
int n,p,q,r,a[100005],min1[100005],max1[100005],min2[100005],max2[100005];
long long ans=-3100000000000000000ll;
inline int Min(int x,int y){return x<y?x:y;}
inline int Max(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d%d%d%d",&n,&p,&q,&r);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=0;i<=n+1;++i) min1[i]=min2[i]=2147483647, max1[i]=max2[i]=-2147483647;
	for(int i=1;i<=n;++i) min1[i]=Min(min1[i-1],a[i]), max1[i]=Max(max1[i-1],a[i]);
	for(int i=n;i>=1;--i) min2[i]=Min(min2[i+1],a[i]), max2[i]=Max(max2[i+1],a[i]);
	for(int j=1;j<=n;++j){
		long long sum=1ll*q*a[j];
		if(p>0) sum+=1ll*p*max1[j];
		else sum+=1ll*p*min1[j];
		if(r>0) sum+=1ll*r*max2[j];
		else sum+=1ll*r*min2[j];
		if(ans<sum) ans=sum;
	}
	printf("%I64d",ans);
	return 0;
}