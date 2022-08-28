#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],b[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",mx+b[i]);
		mx=max(mx,mx+b[i]);
	}
	return 0;
}