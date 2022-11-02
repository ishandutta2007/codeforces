#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
vector<int> g[MAXN],ch;
int c,n,p[MAXN];
long long rez=0;
int dfsc(int s,int f)
{
	int sz=1;
	bool cn=true;
	for(int i=0;i<g[s].size();i++) if(g[s][i]!=f)
	{
		int t=dfsc(g[s][i],s);
		if(t>n/2) cn=false;
		sz+=t;
	}
	if(n-sz>n/2) cn=false;
	if(cn) c=s;
	return sz;
}
int dfsrez(int s,int f)
{
	int sz=1;
	for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) sz+=dfsrez(g[s][i],s);
	rez+=2*min(sz,n-sz);
	return sz;
}
void dfs(int s,int f)
{
	ch.push_back(s);
	for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfs(g[s][i],s);
}
int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfsrez(1,1);
	dfsc(1,1);
	ch.push_back(c);
	for(int i=0;i<g[c].size();i++) dfs(g[c][i],c);
	int t=n/2;
	if(n&1) {p[ch[0]]=ch[t]; p[ch[t]]=ch[2*t]; p[ch[2*t]]=ch[0];}
	for(int i=0;i<n-t;i++) if(p[ch[i]]==0) {p[ch[i]]=ch[i+t]; p[ch[i+t]]=ch[i];}
	printf("%lld\n",rez);
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
}