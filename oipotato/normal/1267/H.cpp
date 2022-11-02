#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int ans[10010],vis[10010],n;
vector<int>vec,tmp;
set<int>s;
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++){int x;scanf("%d",&x);vec.push_back(x);}
		reverse(vec.begin(),vec.end());
		for(int cnt=1;vec.size();cnt++)
		{
			s.clear();
			for(auto i:vec)s.insert(i),vis[i]=0;
			for(auto i:vec)
			{
				if(!vis[i])
				{
					vis[i]=1;
					ans[i]=cnt;
					auto it=s.find(i);
					if(it!=s.begin())it--,vis[*it]=-1,it++;
					it++;if(it!=s.end())vis[*it]=-1;
				}
				s.erase(i);
			}
			tmp.clear();
			for(auto i:vec)if(vis[i]==-1)tmp.push_back(i);
			vec.swap(tmp);
		}
		for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}