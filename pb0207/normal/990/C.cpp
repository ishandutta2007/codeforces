#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=3e5+1e3+7;

vector<char>s[N];

int n;

char a[N];

int pre[N],suf[N];

int main()
{
	scanf("%d",&n);	
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a);
		int len=strlen(a);
		for(int j=0;j<len;j++)
			s[i].push_back(a[j]);
	}
	for(int i=1;i<=n;i++)
	{
		int len=s[i].size();
		int a=0;
		bool flp=true,flf=true;
		int pr=0,sf=0;
		for(int j=0;j<len;j++)
		{
			if(s[i][j]=='(')
				a++;
			else
			{
				if(a>0)
					a--;
				else
					flp=false;
			}
		}
		pr=a;
		a=0;
		for(int j=len-1;j>=0;j--)
		{
			if(s[i][j]==')')
				a++;
			else
			{
				if(a>0)
					a--;
				else
					flf=false;
			}		
		}
		sf=a;
		if(flp)
			pre[pr]++;
		if(flf)
			suf[sf]++;
	}
	long long ans=0;
	for(int i=0;i<=(int)3e5;i++)
		ans+=1ll*pre[i]*suf[i];
	printf("%lld",ans);
}