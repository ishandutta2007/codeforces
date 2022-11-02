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
const int N=200010;
multiset<int>s[2];
vector<pair<int,int>>g[N<<1];
int n,l[N],r[N],t[N],b[N<<1],cnt;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d%d%d",&l[i],&r[i],&t[i]),b[++cnt]=l[i],b[++cnt]=r[i];
	sort(b+1,b+cnt+1);
	cnt=unique(b+1,b+cnt+1)-b-1;
	rep(i,n)
	{
		l[i]=lower_bound(b+1,b+cnt+1,l[i])-b;
		r[i]=lower_bound(b+1,b+cnt+1,r[i])-b;
		g[l[i]].pb(mp(r[i],t[i]-1));
	}
	int ans=n;
	rep(i,cnt)
	{
		for(auto j:g[i])s[j.second].insert(j.first);
		for(int j=0;j<2;j++)
		{
			for(;;)
			{
				auto it=s[j].begin();
				if(it!=s[j].end()&&*it==i)
				{
					s[j].erase(it);
					auto it2=s[!j].begin();
					if(it2!=s[!j].end())ans--,s[!j].erase(it2);
				}
				else break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}