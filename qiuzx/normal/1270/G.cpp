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
#define N 1000010
using namespace std;
ll n,a[N],nxt[N],cnt=0;
bool vis[N];
vector<ll> ans;
int main(){
	ll i,x,T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			nxt[i]=i-a[i];
			if(nxt[i]<0||nxt[i]>=n)
			{
				puts("I DONT KNOW WHAT I AM DOING");
				return 0;
			}
		}
		for(i=0;i<n;i++)
		{
			vis[i]=false;
		}
		x=0;
		while(!vis[x])
		{
			vis[x]=true;
			x=nxt[x];
		}
		for(i=0;i<n;i++)
		{
			vis[i]=false;
		}
		while(!vis[x])
		{
			vis[x]=true;
			x=nxt[x];
			ans.push_back(x);
		}
		printf("%d\n",ans.size());
		for(i=0;i<ans.size();i++)
		{
			printf("%d ",ans[i]+1);
		}
		puts("");
	}
	return 0;
}