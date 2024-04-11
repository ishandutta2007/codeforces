#include<cstdio>
#include<map>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
map<pair<int,int>,vector<int>>dic;
int n,x[1010],y[1010],a[1010],b[1010];
bool vis[1010];
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&x[i],&y[i]);
	rep(i,n)scanf("%d%d",&a[i],&b[i]);
	rep(i,n)
	{
		rep(j,n)dic[{a[i]+x[j],b[i]+y[j]}].push_back(i);
	}
	for(const auto&i:dic)
	{
		if(i.second.size()<n)continue;
		rep(j,n)vis[j]=0;
		for(auto j:i.second)vis[j]=1;
		bool flag=1;
		rep(j,n)if(!vis[j]){flag=0;break;}
		if(flag)
		{
			printf("%d %d\n",i.first.first,i.first.second);
			return 0;
		}
	}
	return 0;
}