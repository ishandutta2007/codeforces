#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const int N=2e6+1e3+7;

int n,k,mx,pos;

char s[N],ans[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s%d",s+1,&k);
		int len=strlen(s+1);
		int t1=-0x7fffffff;
		for(int t=1,x;t<=k;++t)
		{
			scanf("%d",&x);
			if(x+len-1>mx)mx=x+len-1;
			for(int j=max(x,t1),tmp=0;j<=x+len-1;++j)
			ans[j]=s[j-x+1];
			t1=x+len;
		}
	}
	for(int i=1;i<=mx;++i)if(!ans[i])ans[i]='a';
	printf("%s",ans+1);
}