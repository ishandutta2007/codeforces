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
vector<int>g[2];
int ans[200010];
char s[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		g[0].clear();g[1].clear();
		scanf("%s",s+1);
		int cnt=0;
		rep(i,n)
		{
			int x=s[i]-'0';
			if(g[!x].size())
			{
				ans[i]=*g[!x].rbegin();
				g[!x].pop_back();
				g[x].pb(ans[i]);
			}
			else
			{
				g[x].pb(++cnt);
				ans[i]=cnt;
			}
		}
		printf("%d\n",cnt);
		rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}