#include<bits/stdc++.h>
#define sz 111
using namespace std;
int a[sz],b[sz],ans[sz][sz];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	int i,j,k,x,y,z,t1=0,t2=0;
	for (i=1;i<=n;i++) scanf("%d",&a[i]),t1^=a[i];
	for (j=1;j<=m;j++) scanf("%d",&b[j]),t2^=b[j];
	if (t1!=t2) return 0&puts("NO");
	puts("YES");
	for (i=1;i<=n;i++)
	{
		if (i!=n)
			for (j=1;j<=m;j++)
			{
				if (j!=m) printf("0 ");
				else printf("%d",a[i]);
			}
		else 
			for (j=1;j<=m;j++) 
			{
				if (j!=m) printf("%d ",b[j]);
				else printf("%d",t1^a[n]^b[m]);
			}
		puts("");
	}
}