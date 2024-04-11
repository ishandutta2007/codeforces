#include<bits/stdc++.h>
using namespace std;
inline int f(int x)
{
	return x==(x&-x) ? 0 : (1<<(32-__builtin_clz(x)))-x;
}
int main()
{
	int n;
	scanf("%d",&n);
	set<int> que;
	map<int,pair<int,int>> dp;
	tuple<int,int,int> res;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		dp[a]={0,i};
		que.insert(a);
	}
	while(!que.empty())
	{
		int u=*--que.end();
		que.erase(--que.end());
		if(u==0)continue;
		const auto& dpu=dp[u];
		int fa=f(u);
		auto itr=dp.find(fa);
		if(itr!=dp.end())
		{
			auto& dpf=itr->second;
			res=max(res,{dpf.first+dpu.first+1,dpf.second,dpu.second});
			dpf=max(dpf,{dpu.first+1,dpu.second});
		}
		else dp[fa]={dpu.first+1,dpu.second};
		que.insert(fa);
	}
	return 0*printf("%d %d %d\n",get<1>(res),get<2>(res),get<0>(res));
}