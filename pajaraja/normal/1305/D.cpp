#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
vector<int> g[MAXN];
int deg[MAXN];
bool pr[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	for(int i=1;i<=n;i++) deg[i]=g[i].size();
	int sts=n;
	while(sts>1)
	{
		int lf1,lf2,rz=0;
		for(int i=1;i<=n;i++) if(deg[i]==1 && !pr[i]) lf1=i;
		for(int i=1;i<=n;i++) if(deg[i]==1 && i!=lf1 && !pr[i]) lf2=i;
		printf("? %d %d\n",lf1,lf2);
		fflush(stdout);
		scanf("%d",&rz);
		if(rz==lf1 || rz==lf2) {printf("! %d\n",rz); fflush(stdout); return 0;}
		for(int i=0;i<g[lf1].size();i++) deg[g[lf1][i]]--;
		for(int i=0;i<g[lf2].size();i++) deg[g[lf2][i]]--;
		pr[lf1]=pr[lf2]=true;
		sts-=2;
	}
	for(int i=1;i<=n;i++) if(!pr[i]) {printf("! %d\n",i); fflush(stdout); return 0;}
}