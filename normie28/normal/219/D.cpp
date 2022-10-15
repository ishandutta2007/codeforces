#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 #define type typ
vector<ll>gt[200005],type[200005];
ll n,m,i,j,k,u[200005],v[200005],lay[200005],res[200005],a;
void dfs(int x, int k)
{
	lay[x]=k;
	for (int i=0;i<gt[x].size();i++) if (!lay[gt[x][i]]) dfs(gt[x][i],k+1); 
}
void dfs2(int x, int k)
{
//	cout<<"dfs2("<<x<<','<<k<<")\n";
	res[x]=k;
	for (int i=0;i<gt[x].size();i++) dfs2(gt[x][i],k+type[x][i]); 
}
int main()
	{
	 ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<=n-1;i++)
	{
		cin>>u[i]>>v[i];
		gt[u[i]].push_back(v[i]);
		gt[v[i]].push_back(u[i]);
	}
	dfs(1,1);
	for (i=1;i<=n;i++)
	{
//		cout<<lay[i]<<' ';
		gt[i].clear(); res[i]=-1;
	}
	a=0;
	for (i=1;i<=n-1;i++) if (lay[u[i]]<lay[v[i]])
	{
//		cout<<u[i]<<' '<<v[i]<<endl;
		gt[u[i]].push_back(v[i]); type[u[i]].push_back(1);
	}
	else
	{
//		cout<<v[i]<<' '<<u[i]<<endl;
		gt[v[i]].push_back(u[i]); type[v[i]].push_back(-1); a++;
	}
	dfs2(1,a);
	a=1e9+7;
	for (i=1;i<=n;i++) if (res[i]<a) a=res[i];
	cout<<a<<endl;
	for (i=1;i<=n;i++) if (res[i]==a) cout<<i<<' ';
}