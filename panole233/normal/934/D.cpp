#include<cstdio>
#include<cstring>

long long p,a[10001],k,ans[10001];
int n;

bool check(long long a,long long b) {return (a>0&&b>0)||(a<0&&b<0);}

int main()
{
	scanf("%I64d%I64d",&p,&k);
	if (p<k) {printf("1\n%I64d\n",p); return 0;}
	a[0]=-(p/k); n=1;
	if ((!check(p,k))&&p%k!=0) a[0]++;
	while (1)
	{
		a[n]=-(a[n-1]/k);
		if ((!check(a[n-1],k))&&a[n-1]%k!=0) a[n]++;
		if (a[n]==0) break;
		n++;
	}
	ans[0]=a[0]*k+p;
	for (int i=1; i<=n; i++) ans[i]=a[i]*k+a[i-1];
	for (int i=0; i<=n; i++)
		if (ans[i]<0||ans[i]>=k) {printf("-1\n"); return 0;}
	printf("%d\n",n+1);
	for (int i=0; i<=n; i++) printf("%I64d ",ans[i]); printf("\n");
	return 0;
}