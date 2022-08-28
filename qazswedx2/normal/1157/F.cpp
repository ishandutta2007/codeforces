#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],b[1000005],f[1000005],g[1000005],maxn,id;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	for(int i=1;i<=200000;i++)
	{
		if(b[i]>=2) 
		{
			f[i]=f[i-1]+b[i];
			if(f[i-1]) g[i]=g[i-1];
			else g[i]=i;
		}
		else f[i]=b[i],g[i]=i;
		if(f[i]&&f[i]+b[i+1]>maxn) maxn=f[i]+b[i+1],id=i;
	}
	printf("%d\n",maxn);
	int l=g[id],r=(b[id+1]?id+1:id);
	//printf("l=%d,r=%d,id=%d\n",l,r);
	for(int i=l;i<=r;i++)
	{
		for(int j=1;j<=max(1,b[i]-1);j++)
			printf("%d ",i);
		b[i]-=max(1,b[i]-1);
	}
	if(b[r]) printf("%d ",r),b[r]--;
	for(int i=r-1;i>l;i--)
		printf("%d ",i);
	if(b[l]) printf("%d ",l);
	return 0;
}