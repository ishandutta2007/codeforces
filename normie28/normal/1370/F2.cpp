#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
pii ask(const vector<int> &v)
{
	if (v.size()==0)
	return {0,1e9};
	cout<<"?";
	cout<<' '<<v.size();
	for (int g : v) cout<<' '<<g;
	cout<<endl;
	int x,d;
	cin>>x>>d;
	if (x==-1) exit(0);
	return {x,d};
}
void answer(int a, int b)
{
	cout<<"! "<<a<<' '<<b<<endl;
	string s; 
	cin>>s;
	if (s!="Correct") exit(0);
}
int n,m,i,j,k,t,t1,u,v,a,b,tar,root;
vector<int> gt[1001];
vector<int> buc[1001];
vector<int> cur;
int dep[1001],par[1001];
void dfs(int x, int d)
{
//	cout<<"dfs "<<x<<' '<<d<<endl;
	dep[x]=d;
	for (int g : gt[x]) if (!dep[g]) {
	dfs(g,d+1); par[g]=x;}
}
int main()
{
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		for (i=1;i<=n;i++) gt[i].clear();
		
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
		cur.clear();
		for (i=1;i<=n;i++) cur.push_back(i);
		auto res=ask(cur);
		root=res.fi;
		tar=res.se;
		for (i=1;i<=n;i++) dep[i]=0;
		dfs(root,1);
		for (i=0;i<n;i++) buc[i].clear();
		for (i=1;i<=n;i++) buc[dep[i]-1].push_back(i);
		int l=ceil(float(tar)/2);
		int r=tar;
		u=-1;
		while(l<=r)
		{
		//	cout<<l<<' '<<r<<endl;
			int mid=(l+r)/2;
			cur.clear();
			for (i=mid;i<=mid;i++) for (int g : buc[i]) cur.push_back(g);
			res=ask(cur);
			if (res.se==tar)
			{
				u=res.fi;
				l=mid+1;
			}
			else r=mid-1;
		}
		for (i=1;i<=n;i++) dep[i]=0;
		dfs(u,1);
		cur.clear();
		for (i=0;i<n;i++) buc[i].clear();
		for (i=1;i<=n;i++) buc[dep[i]-1].push_back(i);
		for (int g : buc[tar]) cur.push_back(g);
		res=ask(cur);
		answer(u,res.fi);
	}
}