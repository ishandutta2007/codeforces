
 #include<cstdio>
#include<cstring>

int n,t[10000001];
long long x[1000001],ave,m,max,k,sum,f[20000002];

int main()
{
	scanf("%d%I64d",&n,&m);
	for (int i=0; i<=10000000; i++) t[i]=0; ave=0;
	max=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%I64d",&x[i]),t[x[i]]++,ave+=x[i];
		if (x[i]>max) max=x[i];
	}
	ave=ave/m; 
	if (ave==0) {printf("-1"); return 0;} sum=0;
	if (ave==1) {printf("1"); return 0;}
	for (int i=0; i<=max; i++) f[i]=t[i];
	for (int i=max; i>=1; i--)
	{
		f[i]+=f[i<<1]*2+f[(i<<1)+1]+f[(i<<1)-1];
		if (f[i]-f[i<<1]-f[(i<<1)-1]+sum>=m) {printf("%d",i); return 0;}
		sum+=f[i]-f[i<<1]-f[(i<<1)-1];
	}
	printf("-1");
	return 0;
}