#include <cstdio>
using namespace std;
const int maxn=200005;
int tmp[maxn],a[maxn],b[maxn],next[maxn],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		printf("%d\n",n);
		return 0;
	}
	else if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&tmp[i]);
	for(int i=1;i<n;i++)
		a[i]=tmp[i+1]-tmp[i];
	for(int i=1;i<=m;i++)
		scanf("%d",&tmp[i]);
	for(int i=1;i<m;i++)
		b[i]=tmp[i+1]-tmp[i];
	n--;
	m--;
	int j,ans;
	j=0;
	next[1]=0;
	for(int i=2;i<=m;i++)
	{
		while(j>0&&b[j+1]!=b[i])
			j=next[j];
		if(b[j+1]==b[i])
			j++;
		next[i]=j;
	}
	j=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(j>0&&a[i]!=b[j+1])
			j=next[j];
		if(b[j+1]==a[i])
			j++;
		if(j==m)
		{
			ans++;
			j=next[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}