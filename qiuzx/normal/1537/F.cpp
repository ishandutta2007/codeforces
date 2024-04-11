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
#define N 200010
using namespace std;
int n,m,dep[N];
ll val[N],sum=0;
vector<int> vt[N];
queue<int> q;
int main(){
	int i,T,x,y;
	bool bip;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&val[i]);
			dep[i]=-1;
			vt[i].clear();
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			val[i]=(ll)x-val[i];
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			x--;
			y--;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		while(!q.empty())
		{
			q.pop();
		}
		q.push(0);
		dep[0]=0;
		bip=true;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(i=0;i<vt[x].size();i++)
			{
				if(dep[vt[x][i]]==dep[x])
				{
					bip=false;
				}
				if(dep[vt[x][i]]==-1)
				{
					dep[vt[x][i]]=dep[x]^1;
					q.push(vt[x][i]);
				}
			}
		}
		sum=0;
		for(i=0;i<n;i++)
		{
			if(dep[i]==0)
			{
				sum+=val[i];
			}
			else
			{
				sum-=val[i];
			}
		}
		if(!bip)
		{
			if(sum%2==0)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
		else
		{
			if(sum==0)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
	}
	return 0;
}