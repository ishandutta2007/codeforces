#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t,f[1000005],*vis=f+500000,m;
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int nw=0;
		for(int i=1;i<=n;i++)
		{
			vis[nw]--;
			if(s[i]=='0') nw++;
			else nw--;
		}
		scanf("%d%d%s",&n,&m,s+1);
		nw=0;
		for(int i=1;i<=n;i++)
		{
			vis[nw]++;
			if(s[i]=='0') nw++;
			else nw--;
		}
		if(m>150000)
		{
			if(nw<=0)
			{
				printf("0\n");
				continue;
			}
			m=(m-150000)%nw+150000;
		}
		if(m<-150000)
		{
			if(nw>=0)
			{
				printf("0\n");
				continue;
			}
			m=(m+150000)%(-nw)-150000;
		}
		//printf("nw=%d,m=%d\n",nw,m);
		if(nw==0)
		{
			if(vis[m]) printf("-1\n");
			else printf("0\n");
			continue;
		}
		int tans=0;
		while(m<=400000&&m>=-400000)
		{
			tans+=vis[m];
			m-=nw;
		}
		printf("%d\n",tans);
	}
	return 0;
}