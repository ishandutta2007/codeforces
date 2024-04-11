//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define N 200010
#define B 460
using namespace std;
int rint(){
	int ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(int x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
int n,q,dp[B][N],ans[N],id[N];
vector<int> vt[N];
void dfs(int x,int lst)
{
	int i,j;
	for(i=0;i<vt[x].size();++i)
	{
		if(vt[x][i]==lst)
		{
			continue;
		}
		dfs(vt[x][i],x);
		for(j=0;j<B;++j)
		{
			dp[j][x]+=max(dp[j][vt[x][i]]-j,1);
		}
	}
	return;
}
void dfs2(int x,int lst)
{
	for(int i=0;i<B;++i)
	{
		dp[i][x]=0;
	}
	for(int i=0;i<vt[x].size();++i)
	{
		if(vt[x][i]==lst)
		{
			continue;
		}
		dfs2(vt[x][i],x);
		int curmx=-INF;
		for(int j=0;j<B;++j)
		{
			curmx=max(curmx,dp[j][vt[x][i]]-(B-2)*j);
		}
		if(curmx>=B-2)
		{
			for(int j=B-1;j>=0;--j)
			{
				for(int d=0;d<j;++d)
				{
					dp[j][x]=max(dp[j][x],dp[d][x]+dp[j-d-1][vt[x][i]]-1);
				}
			}
		}
		for(int j=0;j<B;++j)
		{
			++dp[j][x];
		}
	}
	return;
}
int main(){
	n=rint();
	for(int i=1;i<n;++i)
	{
		int x=rint()-1,y=rint()-1;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1);
	q=rint();
	for(int i=0;i<q;++i)
	{
		int x=rint()-1,y=rint();
		if(y<B)
		{
			ans[i]=dp[y][x];
		}
		else
		{
			id[i]=x;
			ans[i]=-y;
		}
	}
	dfs2(0,-1);
	for(int i=0;i<q;++i)
	{
		if(ans[i]<0)
		{
			int x=id[i],y=-ans[i];
			for(int j=0;j<B;++j)
			{
				ans[i]=max(ans[i],dp[j][x]-j*y);
			}
		}
		rout(ans[i]),putchar('\n');
	}
	return 0;
}