#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,u,v,a,b;
#define pii pair<int,int>
#define fi first
#define se second
vector<int> res1,res2,buc[200001];
vector<int> bucr[200011];
int quot[200001];
int l[200001],r[200001];
int fin1[200001],fin2[200001];
struct cmp1
{
	int operator()(int a, int b)
	{
		if (r[a]-r[b]) return (r[a]>r[b]);
		return (a>b);
	}
};
struct cmp2
{
	int operator()(pii a, pii b)
	{
		return (a.fi<b.fi);
	}
};
set<int> cands;
priority_queue<int,vector<int>,cmp1> pq1;
set<pii,cmp2> see;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		buc[l[i]].push_back(i);
		quot[r[i]]++;
	}
	for (i=1;i<=n;i++)
	{
		for (int g : buc[i]) pq1.push(g);
		fin1[i]=pq1.top();
		pq1.pop();
	}
	for (i=1;i<=n;i++)
	{
		cands.insert(i-1);
		bucr[r[fin1[i-1]]+1].push_back(i-1);
		for (int g : bucr[i]) cands.erase(g);
		auto it=cands.lower_bound(l[fin1[i]]);
		if (it!=cands.end())
		{
			cout<<"NO\n";
			for (j=1;j<=n;j++) {
			fin2[fin1[j]]=j;
			}
			for (j=1;j<=n;j++) {
			cout<<fin2[j];
			cout<<' ';
			}
			cout<<endl;
			for (j=1;j<=n;j++) {
			if (j==i) fin2[fin1[(*it)]]=j; else if (j==(*it)) fin2[fin1[i]]=j; else fin2[fin1[j]]=j; }
			for (j=1;j<=n;j++) {
			cout<<fin2[j];
			cout<<' ';
			}
			return 0;
		}
	}
	cout<<"YES\n";
	for (i=1;i<=n;i++) fin2[fin1[i]]=i;
	for (i=1;i<=n;i++) cout<<fin2[i]<<' ';
	
}