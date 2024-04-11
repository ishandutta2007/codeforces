#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000005],t[1000005];
int n,m,vis[1005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		int nw=n,fl=1;
		for(int i=1;i<=m;i++)
			vis[t[i]]=0;
		for(int i=m;i>0;i--)
		{
			if(vis[t[i]])
			{
				fl=0;
				break;
			}
			while(nw&&s[nw]!=t[i])
			{
				vis[s[nw]]=1;
				nw--;
			}
			if(!nw)
			{
				fl=0;
				break;
			}
			nw--;
		}
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
}