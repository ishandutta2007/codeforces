#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i>1) sum+=a[i];
		}
		printf("%d\n",min(m,a[1]+sum));
	}
	return 0;
}