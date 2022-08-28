#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,f[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				int x;
				scanf("%d",&x);
				f[i+j]^=x;
			}
		int fl=0;
		for(int i=1;i<=n+m;i++)
			if(f[i]) fl=1;
		if(fl) printf("Ashish\n");
		else printf("Jeel\n");
	}
	return 0;
}