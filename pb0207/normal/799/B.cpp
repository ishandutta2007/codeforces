#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N= 4e5+1;
int n,p[N],a[N],b[N],rank[N],ans[N];
bool use[N];
struct nd{int p,a,b,id;}e[N*2];
bool cmp(nd a1,nd b1){return a1.p<b1.p;}
priority_queue<int>q[4];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&e[i].p),e[i].id=i;
	for(int i=1;i<=n;++i)scanf("%d",&e[i].a);
	for(int i=1;i<=n;++i)scanf("%d",&e[i].b);
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;++i)rank[e[i].id]=i,ans[i]=e[i].p;
//	for(int i=1;i<=n;++i)cout<<rank[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i)
	{
		q[e[i].a].push(-i);
		if(e[i].a!=e[i].b)q[e[i].b].push(-i);
	}
//	for(int i=1;i<=3;++i)
//	{
//		while(!q[i].empty())
//		{
//			int x=q[i].top();q[i].pop();
//			cout<<x<<" ";
//		}
//		cout<<endl;
//	}
	int m;
	cin>>m;
//	for(int i=1;i<=n;++i)q.push(a[i]);
	for(int i=1,c;i<=m;++i)
	{
		scanf("%d",&c);
		while(!q[c].empty())
		{
			int x=q[c].top();
			x=-x;q[c].pop();
			if(use[x])continue;
			use[x]=1;
			printf("%d ",ans[x]);
			goto ddd;
		}
		printf("-1 ");
		ddd:;
	}
	
}