#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> gt[200001];
int dep[200001],used[200001],par[200001],path[200001];
int rep[200001],depr[200001];
int n,m,i,j,k,t,t1,u,v,a,b,root,root2;
vector<vector<int>> seq;
ll res;
void dfs(int x)
{
	used[x]=1;
	for (int g : gt[x]) if (!used[g])
	{
		dep[g]=dep[x]+1;
		dfs(g);
		par[g]=x;
	}
}
vector<int> lis,buc[200001];
void dfs2(int x,int d)
{
	rep[x]=t;
	depr[x]=d;
	buc[t].push_back(x);
	for (int g : gt[x]) if ((!path[g])and(!rep[g])) dfs2(g,d+1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	for (i=1;i<=n;i++) used[i]=0;
	root=1;
	dfs(root);
	for (i=1;i<=n;i++) {
	if (dep[root]<dep[i]) root=i; }
	for (i=1;i<=n;i++) {
	used[i]=0; dep[i]=0; par[i]=0;}
	dfs(root);
	for (i=1;i<=n;i++) if (dep[root2]<dep[i]) root2=i;
	i=root2;
	j=0;
	while(i)
	{
		lis.push_back(i);
		j++;
		path[i]=j;
		i=par[i];
	}
	for (int g : lis) 
	{
		t=g;
		dfs2(g,0);
		sort(buc[g].begin(),buc[g].end(),[](int a, int b){
			return (depr[a]>depr[b]);
		});
		for (int gg : buc[g]) if (depr[gg])
		{
			if (abs(path[g]-path[root])>abs(path[g]-path[root2])) 
			{
				seq.push_back({gg,root,gg});
				res+=depr[gg]+abs(path[g]-path[root]);
			}
			else
			{
				seq.push_back({gg,root2,gg});
				res+=depr[gg]+abs(path[g]-path[root2]);
			}
		}
	}
	res+=ll(lis.size())*ll(lis.size()-1)/2;
	for (int g : lis) if (g!=root)
	{
		seq.push_back({g,root,g});
	}
	cout<<res<<endl;
	for (auto g : seq)
	{
		for (auto gg : g) cout<<gg<<' ';
		cout<<endl;
	}
}