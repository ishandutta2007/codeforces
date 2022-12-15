#include<cstdio>
#include<cstring>

int a[6],b[6],n,x;

int abss(int x) {return x>0?x:-x;}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&x),a[x]++;
	for (int i=1; i<=n; i++) scanf("%d",&x),b[x]++;
	for (int i=1; i<=5; i++)
		if ((a[i]+b[i])&1) {printf("-1"); return 0;}
	int ans=0;
	for (int i=1; i<=5; i++) ans+=abss((a[i]-b[i])/2);
	printf("%d",ans/2);
	return 0;
}