#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll n,m,k,hav[20000010],deg[100010];
string s;
bool vis[100010];
vector<ll> vt[100010],ans;
set<ll> pos;
queue<ll> q;
int main(){
	ll i,j,mask,v,pr,x;
	scanf("%lld%lld%lld",&n,&m,&k);
	memset(hav,-1,sizeof(hav));
	for(i=0;i<n;i++)
	{
		cin>>s;
		v=0;
		for(j=0;j<k;j++)
		{
			if(s[j]=='_')
			{
				v=v*27+26;
			}
			else
			{
				v=v*27+(s[j]-'a');
			}
		}
		hav[v]=i;
	}
	for(i=0;i<m;i++)
	{
		cin>>s>>pr;
		pr--;
		pos.clear();
		for(mask=0;mask<(1<<k);mask++)//places replaced by '_'
		{
			v=0;
			for(j=0;j<k;j++)
			{
				if(mask&(1<<j))
				{
					v=v*27+26;
				}
				else
				{
					v=v*27+(s[j]-'a');
				}
			}
			if(hav[v]!=-1)
			{
				pos.insert(hav[v]);
			}
		}
		if(pos.find(pr)==pos.end())
		{
			puts("NO");
			return 0;
		}
		for(set<ll>::iterator it=pos.begin();it!=pos.end();it++)
		{
			vis[*it]=true;
			if((*it)==pr)
			{
				continue;
			}
			vt[pr].push_back(*it);
			deg[*it]++;
		}
	}
	for(i=0;i<n;i++)
	{
		if(vis[i])
		{
			if(deg[i]==0)
			{
				q.push(i);
			}
		}
	}
	while(!q.empty())
	{
		x=q.front();
		ans.push_back(x);
		q.pop();
		for(i=0;i<vt[x].size();i++)
		{
			if(deg[vt[x][i]]==0)
			{
				continue;
			}
			deg[vt[x][i]]--;
			if(deg[vt[x][i]]==0)
			{
				q.push(vt[x][i]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(vis[i])
		{
			if(deg[i]>0)
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for(i=0;i<ans.size();i++)
	{
		printf("%lld ",ans[i]+1);
	}
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			printf("%lld ",i+1);
		}
	}
	puts("");
	return 0;
}