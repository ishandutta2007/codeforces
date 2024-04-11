#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool vis[N];
vector<int>e[N];
int mx,rt,col[N],n,k;
void two(int now,int father)
{
	col[now]=!col[father];
	for (int to:e[now])
	{
		if (to==father) continue;
		two(to,now);
	}
}
void dfs(int now,int father,int dist)
{
	if (dist>mx) mx=dist,rt=now;
	for (int to:e[now]) if (to!=father) dfs(to,now,dist+1);
}
bool get(int now,int father,int ed,vector<int>&a)
{
	if (now==ed) return a.push_back(now),1;
	for (int to:e[now])
	{
		if (to==father) continue;
		if (get(to,now,ed,a)) return a.push_back(now),1;
	}
	return 0;
}
int dfs1(int now,int father,int c,int delta)
{
	col[now]=c=(c+delta)%k;
	int ret=1;
	for (int to:e[now])
	{
		if (to==father) continue;
		ret=max(ret,dfs1(to,now,c,delta)+1);
	}
	return ret;
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if (k==2)
	{
		two(1,0);
		puts("Yes");
		for (int i=1;i<=n;i++) print(1+col[i]," \n"[i==n]);
		return 0;
	}
	int x,y;
	rt=0,mx=0,dfs(1,0,1),x=rt;
	rt=0,mx=0,dfs(x,0,1),y=rt;
	if (mx<k)
	{
		puts("Yes");
		for (int i=1;i<=n;i++) print(1," \n"[i==n]);
		return 0;
	}
	vector<int>a;
	get(y,0,x,a);
	for (int i:a) vis[i]=1;
	int n1=(mx-1)/2,cnt=0;
	for (int i:a) col[i]=cnt++,cnt%=k;
	for (int i=0;i<=n1;i++)
	for (int to:e[a[i]]) if (!vis[to])
	if (dfs1(to,a[i],col[a[i]],k-1)+i+1>=k)
	return puts("No"),0;
	for (int i=n1+1;i<(int)a.size();i++)
	for (int to:e[a[i]]) if (!vis[to])
	if (dfs1(to,a[i],col[a[i]],1)+(int)a.size()-i>=k)
	return puts("No"),0;
	puts("Yes");
	for (int i=1;i<=n;i++) print(col[i]+1," \n"[i==n]);
	
	return 0;
}