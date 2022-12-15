#include<cstdio>
#include<cstring>

const int mod=1000000007;
int n,x,er[501],num[501],ans;

int main()
{
	scanf("%d",&n);
	er[0]=0;
	for (int i=1; i<=n; i++) er[i]=(er[i-1]<<1|1)%mod;
	memset(num,0,sizeof(num)); ans=er[n-1];
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&x);
		if (x>0) num[x]++;
	}
	for (int i=1; i<=n; i++) ans=(ans-er[num[i]])%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}