#include<cstdio>
#include<cstring>

long long x,ans,sum;
int a[300001],n,ma,s0[310001],s1[310001],s[300001];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%I64d",&x);
		a[i]=0;
		while (x)
		{
			if (x&1) a[i]++;
			x>>=1;
		}
	}
	s[0]=0;
	for (int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
	memset(s0,0,sizeof(s0));
	memset(s1,0,sizeof(s1));
	for (int i=n; i; i--)
	{
		s1[i]=s1[i+1]; s0[i]=s0[i+1];
		if (s[i]&1) s1[i]++; else s0[i]++;
	}
	ans=0;
	for (int i=1; i<=n; i++)
	{
		sum=0; ma=0;
		for (int j=i; j<=n&&j<=i+200; j++)
		{
			sum+=a[j];
			if (a[j]>ma) ma=a[j];
			if ((!(sum&1))&&ma<=(sum>>1)) ans++;
		}
		if (s[i-1]&1) ans+=1ll*s1[i+201]; else ans+=1ll*s0[i+201];
	}
	printf("%I64d\n",ans);
	return 0;
}