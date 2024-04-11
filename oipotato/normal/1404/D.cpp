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
const int N=500010;
vector<pair<int,int>>a[N];
int pos[N][2],chos[N],ans[N],n;
bool vis[N];
int main()
{
	scanf("%d",&n);
	if(n%2==0)
	{
		puts("First");fflush(stdout);
		rep(i,2*n)printf("%d%c",i<=n?i:i-n," \n"[i==2*n]);fflush(stdout);
		int x;scanf("%d",&x);return 0;
	}
	puts("Second");fflush(stdout);
	rep(i,2*n)if(i<=n)scanf("%d",&pos[i][0]);else scanf("%d",&pos[i-n][1]);
	rep(i,n)a[pos[i][0]].pb(mp(i,0)),a[pos[i][1]].pb(mp(i,1));
	int KEY;
	rep(i,n)if(!vis[i])
	{
		int cnt=1;vis[i]=1;chos[i]=0;
		pair<int,int> x=a[pos[i][0]][0].first==i?a[pos[i][0]][1]:a[pos[i][0]][0];
		for(;x.first!=i;)
		{
			vis[x.first]=1;
			x.second^=1;
			chos[x.first]=x.second;
			cnt++;
			x=a[pos[x.first][x.second]][0].first==x.first?a[pos[x.first][x.second]][1]:a[pos[x.first][x.second]][0];
		}
		if(cnt&1)KEY=i;
	}
	int k=0;
	rep(i,n)if(chos[i])k++;
	if((k&1)!=(((n+1)/2)&1))
	{
		chos[KEY]=1;
		pair<int,int> x=a[pos[KEY][1]][0].first==KEY?a[pos[KEY][1]][1]:a[pos[KEY][1]][0];
		for(;x.first!=KEY;)
		{
			x.second^=1;
			chos[x.first]=x.second;
			x=a[pos[x.first][x.second]][0].first==x.first?a[pos[x.first][x.second]][1]:a[pos[x.first][x.second]][0];
		}
	}
	rep(i,n)ans[pos[i][chos[i]]]=i+chos[i]*n;
	rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);fflush(stdout);
	int x;scanf("%d",&x);	
	return 0;
}