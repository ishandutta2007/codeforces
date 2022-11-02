#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
set<pair<int,int>> s[100010];
int n,m,ans;
int get(int x,int z)
{
	auto it=s[x].lower_bound({z,0});
	if(it==s[x].begin())return 0;
	it--;
	return it->second;
}
void modify(int x,int z,int ans)
{
	auto it=s[x].lower_bound({z,0});
	for(;it!=s[x].end()&&it->second<=ans;)
	{
		s[x].erase(it);
		it=s[x].lower_bound({z,0});
	}
	it=s[x].upper_bound({z,2000000});
	if(it==s[x].begin())s[x].insert({z,ans});
	else
	{
		it--;
		if(it->second<ans)s[x].insert({z,ans});
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		modify(y,z,get(x,z)+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(auto j:s[i])
		{
			ans=max(ans,j.second);
		}
	}
	printf("%d\n",ans);
	return 0;
}