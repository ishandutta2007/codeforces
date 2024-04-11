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
#define ll unsigned long long
#define N 80010
using namespace std;
ll n,ans,sonsz[N],mns=0;
vector<ll> vt[N];
void dfs(ll x,ll lst)
{
	sonsz[x]=1;
	ll i,sz,chs=0;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]==lst)
		{
			continue;
		}
		dfs(vt[x][i],x);
		chs+=sonsz[vt[x][i]]*sonsz[x];
		sonsz[x]+=sonsz[vt[x][i]];
	}
	sz=sonsz[x]-1;
	mns+=chs*chs+chs*2*(n-sz-1)*(sz+1);
	return;
}
int main(){
	ll i,x,y;
	scanf("%I64d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	ans=n*(n-1)/2;
	ans*=ans;
	dfs(0,-1);
	printf("%I64d\n",ans-mns);
	return 0;
}