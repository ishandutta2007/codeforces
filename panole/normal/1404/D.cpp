#include<bits/stdc++.h>
using namespace std;

int n,p[500010][2],a[1000010],ans[500010];
bool bo[500010];

int inv(int x) {return x<=n?x+n:x-n;}

int main()
{
	scanf("%d",&n);
	if (!(n&1))
	{
		puts("First");
		for (int j=0; j<2; j++)
			for (int i=1; i<=n; i++) printf("%d ",i);
		puts(""),fflush(stdout);
		return 0;
	}
	puts("Second"),fflush(stdout);
	for (int i=1; i<=2*n; i++) 
	{
		scanf("%d",&a[i]);
		p[a[i]][(p[a[i]][0]>0)]=i;
	}
	long long sum=0;
	for (int i=1; i<=n; i++) if (!bo[i])
	{
		int x=i,y;
		sum+=p[x][0],y=inv(p[x][1]),bo[x]=1;
		while (!bo[a[y]])
		{
			if (p[a[y]][1]==y) swap(p[a[y]][0],p[a[y]][1]);
			x=a[y],sum+=p[x][0],y=inv(p[x][1]),bo[x]=1;
		}
	}
	for (int i=1; i<=n; i++) ans[i]=p[i][sum%(2*n)!=0];
	for (int i=1; i<=n; i++) printf("%d ",ans[i]);puts("");fflush(stdout);
	return 0;
}