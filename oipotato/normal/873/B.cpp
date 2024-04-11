#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int s[100010],pos[100010],ans,n,x;
char st[100010];
int main()
{
	scanf("%d",&n);
	scanf("%s",st);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+(st[i-1]=='0'?-1:1);
	}
	memset(pos,-1,sizeof(pos));
	pos[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>=0)
		{
			if(pos[s[i]]==-1)
			{
				pos[s[i]]=i;
			}
			ans=max(ans,i-pos[s[i]]);
		}
	}
	memset(pos,-1,sizeof(pos));
	pos[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]<=0)
		{
			if(pos[-s[i]]==-1)
			{
				pos[-s[i]]=i;
			}
			ans=max(ans,i-pos[-s[i]]);
		}
	}
	printf("%d\n",ans);
	return 0;
}