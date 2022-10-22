// By: Little09
// Problem: E. Purple Crayon
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
vector<int>t[N],s[N];

int f[N],g[N],dis[N];
void dfs(int x,int fa)
{
	dis[x]=dis[fa]+1,f[x]=x,g[x]=-1;
	for (int i=0;i<t[x].size();i++)
	{
		if (t[x][i]==fa) continue;
		dfs(t[x][i],x);
		s[x].push_back(t[x][i]);
		if (dis[f[t[x][i]]]>dis[f[x]])
		{
			f[x]=f[t[x][i]];
			g[x]=t[x][i];
		}
	}
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
struct point
{
	int id,x;
	bool operator < (const point & o) const
	{
		if (x==o.x) return id<o.id;
		return x<o.x;
	}
};
ll e[N];
priority_queue<point>q;
void work(int x,int y)
{
	for (int i=0;i<s[x].size();i++)
	{
		if (s[x][i]==g[x]) work(s[x][i],y);
		else 
		{
			point u;
			u.id=s[x][i],u.x=dis[f[u.id]]-dis[x];
			//cout << u.id << " " << u.x << endl;
			q.push(u);
		} 
	}
	if (x==y) return;
}
ll clc(ll x,ll i)
{
	return x*x-n*x-i*i+n*i;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		t[x].push_back(y),t[y].push_back(x);
	}
	dfs(1,-1);
	point S;
	S.id=1,S.x=dis[f[1]];
	q.push(S);
	int R=0;
	e[0]=n;
	for (int i=1;i<=m;i++)
	{
		if (q.empty()) 
		{
			e[i]=e[i-1];
			continue;
		}
		point u=q.top();
		q.pop();
		R+=u.x;
		work(u.id,f[u.id]);
		e[i]=n-R;
	}
	ll ans=-inf;
	for (int i=0;i<=m;i++)
	{
		ll res=inf;
		res=min(res,clc(0,i));
		res=min(res,clc(e[i],i));
		int u=n/2;
		if (u<=e[i]) res=min(res,clc(u,i));
		if (u+1<=e[i]) res=min(res,clc(u+1,i));
		if (u-1<=e[i]&&u-1>=0) res=min(res,clc(u-1,i));
		ans=max(ans,res);
	}
	cout << ans;
	return 0;
}