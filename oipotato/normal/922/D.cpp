#include<bits/stdc++.h>
using namespace std;
struct data
{
	int a,b;
	friend bool operator <(const data &a,const data &b)
	{
		return 1ll*a.a*b.b>1ll*a.b*b.a;
	}
}p[100010];
int n;
char s[100010];
int main()
{
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;j++)
		{
			if(s[j]=='s')
			{
				p[i].a++;
			}
			else
			{
				p[i].b++;
				ans+=p[i].a;
			}
		}
	}
	sort(p+1,p+n+1);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		ans+=1ll*sum*p[i].b;
		sum+=p[i].a;
	}
	printf("%I64d\n",ans);
	return 0;
}