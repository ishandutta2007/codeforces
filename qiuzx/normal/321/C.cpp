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
#define ll int
#define N 100010
using namespace std;
ll n,k,sonsz[N],mxsz[N],ans[N];
bool cent[N];
vector<ll> vt[N],pas;
void get_sonsize(ll x,ll lst)
{
	ll i;
	mxsz[x]=0;
	sonsz[x]=1;
	pas.push_back(x);
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]==lst||cent[vt[x][i]])
		{
			continue;
		}
		get_sonsize(vt[x][i],x);
		mxsz[x]=max(mxsz[x],sonsz[vt[x][i]]);
		sonsz[x]+=sonsz[vt[x][i]];
	}
	return;
}
ll get_cent(ll x)
{
	pas.clear();
	get_sonsize(x,-1);
	ll i,ret=-1;
	for(i=0;i<pas.size();i++)
	{
		if(max((ll)pas.size()-sonsz[pas[i]],mxsz[pas[i]])*2<=pas.size())
		{
			ret=pas[i];
		}
	}
	return ret;
}
void dfs(ll x,ll col)
{
	if(col>=26)
	{
		puts("Impossible!");
		exit(0);
	}
	ll nw=get_cent(x),i;
	ans[nw]=col;
	cent[nw]=true;
	for(i=0;i<vt[nw].size();i++)
	{
		if(!cent[vt[nw][i]])
		{
			dfs(vt[nw][i],col+1);
		}
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,0);
	for(i=0;i<n;i++)
	{
		printf("%c ",'A'+(char)ans[i]);
	}
	puts("");
	return 0;
}