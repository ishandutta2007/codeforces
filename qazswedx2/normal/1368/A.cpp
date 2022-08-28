#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&n);
		int ans=0;
		while(a<=n&&b<=n)
		{
			ans++;
			if(a>b) swap(a,b);
			a+=b;
		}
		printf("%d\n",ans);
	}
	return 0;
}