#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n;
ll sum,xsum;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=xsum=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			sum+=x;
			xsum^=x;
		}
		printf("2\n");
		printf("%I64d %I64d\n",xsum,sum+xsum);
	}
	return 0;
}