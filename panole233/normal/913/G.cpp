#include<cstdio>
#include<cstring>

const long long mod=1000000000000000000ll;

long long shi[20],er[20],wu[20],x,ans,now;
int n;

long long mul(long long a,long long b)
{
	long long t=0;
	while (b)
	{
		if (b&1) t=(t+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return t;
}

long long quickmi(long long a,long long b)
{
	long long t=1;
	while (b)
	{
		if (b&1) t=mul(t,a);
		a=mul(a,a);
		b>>=1;
	}
	return t;
}

int main()
{
	shi[0]=1;
	for (int i=1; i<=18; i++) shi[i]=shi[i-1]*10ll;
	wu[0]=1; wu[1]=4;
	for (int i=2; i<=18; i++) wu[i]=wu[i-1]*5ll;
	for (int i=0; i<=18; i++) er[i]=quickmi(2,wu[i]);
	scanf("%d",&n);
	while (n--)
	{
		scanf("%I64d",&x); x=x*1000000ll/131072ll+1;
		if (x%5==0) x++; x*=131072;
		ans=1000; now=quickmi(2,ans);
		for (int i=1; shi[i-1]<=x; i++)
			while ((now-x)%shi[i]!=0)
				now=mul(now,er[i-1]),ans+=wu[i-1];
		printf("%I64d\n",ans);
	}
	return 0;
}