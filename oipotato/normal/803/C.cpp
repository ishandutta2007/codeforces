#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
long long ans,n,k;
int len;
bool check(long long n,long long k){return k*(k+1)/2<=n;}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	if(k>=200000)
	{
		printf("-1");
		exit(0);
	}
	len=(int)sqrt(n);
	ans=-1;
	if(check(n,k))ans=1;
	for(int i=2;i<=len;i++)
	if(n%i==0)
	{
		if(check(n/i,k))ans=max(ans,(long long)i);
		if(check(i,k))ans=max(ans,n/i);
	}
	if(ans==-1)printf("-1");
	else
	{
		for(int i=1;i<k;i++)printf("%I64d ",ans*i);
		printf("%I64d",n-k*(k-1)/2*ans);
	}
	return 0;
}