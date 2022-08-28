#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],b[1000005],nw1,nw2;
bool cmp(const int x,const int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&n);
	nw1=nw2=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2) nw1=i;
		else nw2=i;
	}
	if(nw1==-1||nw2==-1)
	{
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	/*for(int i=1;i<=n;i++)
		b[i]=i;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		
	}*/
	return 0;
}