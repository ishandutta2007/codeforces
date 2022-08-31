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
		
		scanf("%s",s+2);
		n=strlen(s+2);
		int ans=0;
		for(int i=2;i<=n+1;i++)
		{
			if(s[i]==s[i-1]||s[i]==s[i-2])
				s[i]=0,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}