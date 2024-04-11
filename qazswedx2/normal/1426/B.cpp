#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int fl=0;
		for(int i=1;i<=n;i++)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(b==c) fl=1;
		}
		if(fl==1&&m%2==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}