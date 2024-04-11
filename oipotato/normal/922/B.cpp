#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int k=i^j;
			if(k>=j&&k<=n&&i+j>k)
			{
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}