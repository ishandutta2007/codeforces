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
char s[200010];
int cnt[20];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int ans=n-1;
		rep(i,10)cnt[i-1]=0;
		rep(i,n)cnt[s[i]-'0']++;
		int mx=0;
		rep(i,10)mx=max(mx,cnt[i-1]);
		ans=min(ans,n-mx);
		for(int i=0;i<10;i++)for(int j=0;j<10;j++)
		{
			int num=0;
			rep(k,n)if(s[k]-'0'==i)
			{
				int p=k+1;
				for(;p<=n&&s[p]-'0'!=j;p++);
				if(p>n)break;
				num+=2;
				k=p;
			}
			ans=min(ans,n-num);
		}
		printf("%d\n",ans);
	}
	return 0;
}