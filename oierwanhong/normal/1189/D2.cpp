//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}

/**********/
#define MAXN 5011
struct Edge
{
	ll v,w,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN],ind[MAXN];
void adde(ll u,ll v,ll w,bool p=1)
{
	++ind[v];
	++cnt;
	e[cnt].v=v,e[cnt].w=w;
	e[cnt].nxt=last[u];last[u]=cnt;
	if(p)adde(v,u,w,0);
}
ll leaf[2][2];
struct tedge
{
	ll u,v,w;
}te[MAXN<<1|1];
std::vector<tedge>ans;
void dfs(ll u,ll pre,ll p,ll num)
{
	if(ind[u]==1)
	{
		if(!leaf[num][0])leaf[num][0]=u;
		leaf[num][1]=u;
	}
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==pre||v==p)continue;
		dfs(v,u,p,num);
	}
}
ll n;
int main()
{
	n=read();
	for(ll i=1;i<n;++i)
	{
		te[i].u=read(),te[i].v=read(),te[i].w=read();
		adde(te[i].u,te[i].v,te[i].w);
		
	}
	for(ll i=1;i<=n;++i)
		if(ind[i]==2)
		{
			std::cout<<"NO";
			return 0;
		}
	std::cout<<"YES"<<std::endl;
	for(ll i=1;i<n;++i)
	{
		ll u=te[i].u,v=te[i].v,w=te[i].w>>1;
		leaf[0][0]=leaf[0][1]=leaf[1][0]=leaf[1][1]=0;
		dfs(u,u,v,0),dfs(v,v,u,1);
		ans.push_back(tedge{leaf[0][0],leaf[1][0],w});
		ans.push_back(tedge{leaf[0][1],leaf[1][1],w});
		if(leaf[0][0]!=leaf[0][1])ans.push_back(tedge{leaf[0][0],leaf[0][1],-w});
		if(leaf[1][0]!=leaf[1][1])ans.push_back(tedge{leaf[1][0],leaf[1][1],-w});
	}
	std::cout<<ans.size()<<std::endl;
	for(ll i=0;i<ans.size();++i)
		std::cout<<ans[i].u<<" "<<ans[i].v<<" "<<ans[i].w<<std::endl;
	return 0;
}