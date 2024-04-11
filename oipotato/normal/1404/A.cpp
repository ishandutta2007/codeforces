#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
char s[300010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		bool flag=1;
		rep(i,k)
		{
			int tmp=-1;
			for(int j=i;j<=n;j+=k)if(s[j]!='?')
			{
				int x=s[j]-'0';
				if(tmp==-1)tmp=x;
				else if(tmp!=x)tmp=-2;
			}
			if(tmp==-2){flag=0;break;}
			if(tmp!=-1)for(int j=i;j<=n;j+=k)s[j]=tmp+'0';
		}
		if(!flag){puts("NO");continue;}
		int now=0,re=0;
		rep(i,k)if(s[i]=='?')re++;else if(s[i]=='1')now++;else now--;
		puts(abs(now)<=re?"YES":"NO");
	}
	return 0;
}