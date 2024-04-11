#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int t,n,m;
char s[2005][2005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		int nw=1,fl=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='#') nw=2*nw%mod;
				else fl=1;
			}
		if(!fl) nw=(nw+mod-1)%mod;
		printf("%d\n",nw);
	}
	return 0;
}