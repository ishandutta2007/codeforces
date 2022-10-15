#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<501> r[501][61][2];
bitset<501> c[501][61][2];
ll cur[501],cur2[501]; bitset<501> ha;
ll n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v>>a;
		r[u][0][a][v]=1;
		c[v][0][a][u]=1;
	}
	for (t=0;t<=60;t++)
	{
		if (t)
		{
		
		for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			ha=r[i][t-1][0];
			ha&=c[j][t-1][1];
			if (ha.count())
			{
				r[i][t][0][j]=1;
				c[j][t][0][i]=1;
			}
			ha=r[i][t-1][1];
			ha&=c[j][t-1][0];
			if (ha.count())
			{
				r[i][t][1][j]=1;
				c[j][t][1][i]=1;
			}
		}
		}
	//	for (i=1;i<=n;i++) for (j=1;j<=n;j++)
	//	{
	//		if (dp[i][j][t][0]) cout<<"there is a path from "<<i<<" to "<<j<<" with length 2^"<<t<<" in the 0 type\n";
	//		if (dp[i][j][t][1]) cout<<"there is a path from "<<i<<" to "<<j<<" with length 2^"<<t<<" in the 1 type\n";
	//	}
	//	cout<<endl;
	}
	u=0;
	v=0;
	for (i=1;i<=n;i++) cur[i]=1;
	for (t=60;t>=0;t--)
	{
		for (i=1;i<=n;i++) cur2[i]=0;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++)
		{
			cur2[j]|=(cur[i]&bool(r[i][t][v][j]));
	//		cout<<i<<"->"<<j<<" at length 2^"<<t<<" at type "<<v<<":\n";
	//		cout<<cur[i]<<' '<<dp[i][j][t][v]<<endl;
		}
		int good=0;
		for (i=1;i<=n;i++) good|=cur2[i];
		if (good)
		{
			v^=1;
			u+=(ll(1)<<t);
			for (i=1;i<=n;i++) cur[i]=cur2[i];
	//		cout<<"good "<<t<<endl;
	//		for (i=1;i<=n;i++) cout<<cur[i]<<' ';
	//		cout<<endl;
		}	
	}
	if (u>1e18) cout<<-1; else cout<<u;
}