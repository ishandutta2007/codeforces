#include <bits/stdc++.h>
using namespace std;
struct edge {int dest=0; int no=0;};
int n,m,used[300001],d[300001],sum[300001],k,t,i,j;
vector<edge> gt[300001],st[300001];
vector<int> res;
int build(int x)
{
//	cout<<"building "<<x<<endl;
//	cout<<"d["<<x<<"]="<<d[x]<<endl;
	int v;
	used[x]=1;
	for (int i=0; i<gt[x].size();i++)
	{
	v=gt[x][i].dest;
	if (!used[v])
	{
		st[x].push_back({v,gt[x][i].no});
		sum[x]+=build(v);	
	}
	}
	
	if (d[x]) sum[x]++;
	return sum[x];
}
void solve(int x)
{
//	cout<<"solving "<<x<<endl;
	int v;
	for (int i=0; i<st[x].size();i++)
	{
	v=st[x][i].dest;
	if ((sum[v]%2))
	{
		res.push_back(st[x][i].no);
	}
	solve(v);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	k=0;
	for (i=1;i<=n;i++) {cin>>d[i]; if (d[i]>=0) k+=d[i];}
	for (i=1;i<=n;i++) if (d[i]==-1) if (k%2) {d[i]=1; k++;} else {d[i]=0;}
	if (k%2) {cout<<-1; return 0;}
	for (j=1;j<=m;j++)
	{
		cin>>k>>t;
		gt[k].push_back({t,j});
		gt[t].push_back({k,j});
	}
	k=build(1);
	solve(1);
	cout<<res.size()<<endl;
	for (i=0;i<res.size();i++) cout<<res[i]<<endl;
}