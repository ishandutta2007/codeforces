#include<cstdio>
#include<cstring>

const long long mod=1e9+7;

int n,x,p[1000001];
long long t[1000001],val[1000001],ans,nn,er[1000001],f[200001];
bool b[1000001];

int main()
{
	scanf("%d",&n);
	memset(t,0,sizeof(t));
	for (int i=1; i<=n; i++) scanf("%d",&x),t[x]++;
	memset(b,1,sizeof(b));
	for (int i=2; i<=1000000; i++)
		if (b[i])
			for (int j=i<<1; j<=1000000; j+=i) b[j]=0;
	for (int i=2; i<=1000000; i++) if (b[i]) p[++p[0]]=i;
	for (int i=2; i<=1000000; i++) val[i]=i;
	for (int i=2; i<=1000000; i++)
		for (int j=i<<1; j<=1000000; j+=i) val[j]-=val[i]; 
	ans=0;
	er[0]=1;
	for (int i=1; i<=n; i++) er[i]=er[i-1]*2%mod;
	f[1]=1;
	for (int i=2; i<=n; i++) f[i]=(f[i-1]*2+er[i-1])%mod;
	for (int i=2; i<=1000000; i++)
	{
		nn=0;
		for (int j=i; j<=1000000; j+=i) nn+=t[j];
		if (nn) ans=(ans+f[nn]*val[i])%mod;
	}
	printf("%I64d",ans);
	return 0;
}