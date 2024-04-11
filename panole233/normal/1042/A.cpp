#include<cstdio>
#include<cstring>

int n,m,a[10001],ma,s;

int main()
{
	scanf("%d%d",&n,&m); s=ma=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]);
		if (a[i]>ma) ma=a[i];
		s+=a[i];
	}
	int ans1,ans2;
	if (ma*n>=s+m) ans1=ma; else 
	{
		ans1=(s+m)/n;
		if ((s+m)%n!=0) ans1++;
	}
	ans2=ma+m;
	printf("%d %d\n",ans1,ans2);
	return 0;
}