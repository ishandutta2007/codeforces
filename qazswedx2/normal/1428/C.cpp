#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int cta=0,ctb=0,ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='A') cta++;
			else
			{
				if(cta) cta--,ans++;
				else ctb++;
			}
		ans+=ctb/2;
		printf("%d\n",n-2*ans);
	}
	return 0;
}