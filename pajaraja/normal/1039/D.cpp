#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
vector<int> g[MAXN];
int sz,arr[MAXN],m[2][MAXN],a[MAXN],p[MAXN],q[MAXN],b[MAXN],n;
int dfs(int s,int f)
{
	for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfs(g[s][i],s);
	a[sz++]=s;
	q[s]=f;
}
int val(int k)
{
	int x=0;
	for(int i=1;i<n;i++) m[0][i]=m[1][i]=0;
	for(int i=0;i<n;i++)
	{
		if(m[0][i]+m[1][i]+1>=k) {x++; continue;}
		if(m[0][i]+1>m[0][p[i]]) {m[1][p[i]]=m[0][p[i]]; m[0][p[i]]=m[0][i]+1;}
		else if(m[0][i]+1>m[1][p[i]]) m[1][p[i]]=m[0][i]+1;
	}
	return x;
}
int main()
{
	int c=100,cur=1;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfs(1,1);
	for(int i=0;i<n;i++) b[a[i]]=i;
	for(int i=0;i<n;i++) p[i]=b[q[a[i]]];
	int x;
	do{x=val(cur++); printf("%d\n",x);} while(x>c);
	for(int i=c;i>=0;i--)
	{
		if(val(cur)!=i || cur>n) continue;
		int l=cur,r=n;
		while(l!=r)
		{
			int s=(l+r+1)/2;
			if(val(s)==i) l=s;
			else r=s-1;
		}
		while(cur<=l) {printf("%d\n",i); cur++;}
	}
}