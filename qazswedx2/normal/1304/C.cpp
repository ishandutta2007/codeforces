#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,l,r;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int las=0,fl=1;
		l=r=m;
		for(int i=1;i<=n;i++)
		{
			int tt,x,y;
			scanf("%d%d%d",&tt,&x,&y);
			l-=(tt-las);
			r+=(tt-las);
		//	printf("i=%d,l=%d,r=%d\n",i,l,r);
			if(y<l||x>r) fl=0;
			l=max(l,x);
			r=min(r,y);
			las=tt;
		}
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}