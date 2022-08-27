#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			sum+=x;
		}
		if(sum%n==0) printf("0\n");
		else printf("1\n");
	}
}