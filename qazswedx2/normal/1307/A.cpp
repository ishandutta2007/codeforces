#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,a[100005],ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=2;i<=n;i++)
		{
			while(a[i]&&m>=i-1)
			{
				m-=i-1;
				a[i]--;
				a[1]++;
			}
		}
		printf("%d\n",a[1]);
	}
	return 0;
}