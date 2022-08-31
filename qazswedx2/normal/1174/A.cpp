#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[2000005];
int main()
{
	scanf("%d",&n);
	n*=2;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int nw=a[1],fl=1;
	for(int i=2;i<=n;i++)
		if(a[i]!=nw)
		{
			fl=0;
			break;
		}
	if(fl)
	{
		printf("-1");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}