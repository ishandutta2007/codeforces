#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ct1,ct2,nw=0,ans;
char s[1000005];
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='(') ct1++;
		else ct2++;
	if(ct1!=ct2)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(') nw++;
		else
		{
			nw--;
			if(nw<0)
			{
				int ct=1;
				for(int j=i+1;j<=n;j++)
				{
					if(s[j]=='(') nw++;
					else nw--;
					ct++;
					if(nw==0)
					{
						i=j;
						break;
					}
				}
				ans+=ct;
			}
		}
	}
	printf("%d",ans);
	return 0;
}