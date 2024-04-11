#include<cstdio>
using namespace std;
const int MOD=1000000007;
int C,p,n,a[200010],ans1,ans2,opt;
int quick_pow(int x,int n)
{
	int tans=1,tmp=x;
	for(;n;n>>=1)
	{
		if(n&1)tans=(long long)tans*tmp%MOD;
		tmp=(long long)tmp*tmp%MOD;
	}
	return tans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==1)
	{
		printf("%d",a[1]);
		return 0;
	}
	if(n==2)
	{
		printf("%d",(a[1]+a[2])%MOD);
		return 0;
	}
	if(n==3)
	{
		printf("%d",((long long)a[1]+2*a[2]-a[3]+MOD)%MOD);
		return 0;
	}
	if(n%2)
	{
		n--;
		for(int i=1;i<=n;i++)
		if(i%2)a[i]=(a[i]+a[i+1])%MOD;
		else a[i]=(a[i]-a[i+1]+MOD)%MOD;
	}
	C=1;
	p=n/2-1;
	ans1=a[1];
	ans2=a[2];
	opt=1;
	for(int i=2;i<=n/2;i++)
	{
		C=(long long)C*(p-i+2)%MOD*quick_pow(i-1,MOD-2)%MOD;
		ans1=(ans1+(long long)C*a[i*2-1]%MOD)%MOD;
		ans2=(ans2+(long long)C*a[i*2]%MOD+MOD)%MOD;
		opt=-opt;
	}
	printf("%d",((long long)ans1+opt*ans2+MOD)%MOD);
	return 0;
}