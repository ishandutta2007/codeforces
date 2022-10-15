#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pathcnt[200001];
ll dp[200001];
int val[200001];
int eu[200001],ev[200001],ew[200001];
int n,m,i,j,k,t,t1,u,v,a,b;
vector<int> buc[200001];
vector<int> gt[200001];
int used[200001];
void dfs(int x)
{
	used[x]=1;
	t++;
	for (int g : gt[x]) if (!used[g]) dfs(g);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>val[i];
	}
	for (i=1;i<n;i++)
	{
		cin>>eu[i]>>ev[i];
		ew[i]=__gcd(val[eu[i]],val[ev[i]]);
		buc[ew[i]].push_back(i);
	}
	for (i=1;i<=200000;i++)
	{
		for (j=i;j<=200000;j+=i)
		for (int g : buc[j])
		{
			gt[eu[g]].push_back(ev[g]);
			gt[ev[g]].push_back(eu[g]);
		}
		for (j=i;j<=200000;j+=i)
		for (int g : buc[j]) if (!used[eu[g]])
		{
			t=0;
			dfs(eu[g]);
			pathcnt[i]+=ll(t)*ll(t-1)/2;
		}
		for (j=i;j<=200000;j+=i)
		for (int g : buc[j])
		{
			gt[eu[g]].clear();
			gt[ev[g]].clear();
			used[eu[g]]=0;
			used[ev[g]]=0;
		}
	}
	for (i=200000;i>=1;i--)
	{
		dp[i]=pathcnt[i];
		for (j=2*i;j<=200000;j+=i) dp[i]-=dp[j];
	}
	for (i=1;i<=n;i++) dp[val[i]]++;
	for (i=1;i<=200000;i++) if (dp[i]) cout<<i<<' '<<dp[i]<<endl;
}