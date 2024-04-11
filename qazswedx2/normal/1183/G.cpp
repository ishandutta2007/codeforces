#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
struct edge
{
	int v,nxt;
}e[5000005];
int t,n,a[1000005],vis[1000005],fvis[1000005],tt,h[1000005];
vector<int> vvis[1000005];
void add(int u,int v)
{
	e[++tt].v=v;
	e[tt].nxt=h[u];
	h[u]=tt;
}
long long ans,ans1;
bool cmp(const int x,const int y)
{
	return x>y;
}
multiset<int> st;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;ans1=0;
		tt=0;
		for(int i=1;i<=n;i++) h[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d%d",&a[i],&x);
			vis[a[i]]++;
			if(x==1) fvis[a[i]]++;
		}
		for(int i=1;i<=n;i++)
			vvis[vis[i]].push_back(fvis[i]);
		for(int i=1;i<=n;i++)
		{
			sort(vvis[i].begin(),vvis[i].end());
			//for(int j=0;j<vvis[i].size();j++)
			//	add(i,vvis[i][j]);
		}
		for(int i=n;i>0;i--)
		{
			if(!vvis[i].empty())
			{
				for(int j=0;j<vvis[i].size();j++)
					st.insert(vvis[i][j]);
			}
			if(!st.empty())
			{
				ans+=i;
				multiset<int>::iterator it=st.end();
				it--;
				ans1+=min(*it,i);
				st.erase(it);
			}
		}
		while(!st.empty()) st.erase(st.begin());
		for(int i=1;i<=n;i++)
			while(!vvis[i].empty()) vvis[i].pop_back();
		for(int i=1;i<=n;i++)
			vis[i]=fvis[i]=0;
		printf("%I64d %I64d\n",ans,ans1);
	}
	return 0;
}