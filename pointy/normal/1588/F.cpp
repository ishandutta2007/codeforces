// Author: Little09
// Problem: CF1588F Jumping Through the Array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1588F
// Memory Limit: 500 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
const int B=700,N=4e5+5;
int n,m;
ll a[N],q[N][3],ans[N],add[N],v[N];
int p[N],g[N];
int b[N],cnt,tot;
int vis[N];
int ttt[N],timttt=0;
int col[N],w[N];
ll f[2000][2000];
int t[N],h[N],nxt[N],Cnt;
inline void addd(int x,int y)
{
	t[++Cnt]=y;
	nxt[Cnt]=h[x];
	h[x]=Cnt;
}
bool ab;
 
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
 
void dfs(int x)
{
	if (col[x]!=-1) return;
	col[x]=tot;
	f[tot][g[x]]++;
	for (int i=h[x];i;i=nxt[i]) 
	{
		dfs(t[i]);
	}
}
 
void change(int x,ll y)
{
	if (ttt[x]==timttt) return;
	ttt[x]=timttt;
	add[x]+=y;
	change(w[x],y);
}
 
inline void calc(int id,int x,ll y)
{
	ll res=0;
	for (int i=1;i<=tot;i++)
	{
		res+=add[i]*f[i][x];
	}
	ans[id]+=res*y;
}
 
void work(int l,int r)
{
	cnt=0,tot=0,Cnt=0;
	mem(nxt),mem(h),mem(t);
	for (int i=1;i<=n;i++) col[i]=-1,vis[i]=0;
	for (int i=l;i<=r;i++)
	{
		if (q[i][0]!=1) continue;
		b[++cnt]=q[i][1]-1;
		b[++cnt]=q[i][2];
	}
	b[++cnt]=n;
	for (int i=l;i<=r;i++)
	{
		if (q[i][0]!=3) continue;
		vis[q[i][1]]=1,vis[q[i][2]]=1;
	}
	for (int i=l;i<=r;i++)
	{
		if (q[i][0]!=2) continue;
		vis[q[i][1]]|=2;
	}
	sort(b+1,b+cnt+1);
	cnt=unique(b+1,b+cnt+1)-b-1;
	// for (int i=1;i<=cnt;i++) cout << b[i] << " ";
	// cout << endl;
	int las=0;
	for (int i=1;i<=cnt;i++)
	{
		for (int j=las;j<=b[i];j++) g[j]=i;
		las=b[i]+1;
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i]&1) continue;
		addd(p[i],i),addd(i,p[i]);
	}
	
	for (int i=1;i<=n;i++)
	{
		if (col[i]!=-1) continue;
		if (vis[i]==0) continue;
		tot++;
		add[tot]=0;
		for (int j=0;j<=cnt;j++) f[tot][j]=0;
		dfs(i);
		for (int j=1;j<=cnt;j++) f[tot][j]+=f[tot][j-1];
	}
	++tot;
	for (int i=1;i<=n;i++) if (col[i]==-1) col[i]=tot;
	add[tot]=0;
	for (int j=0;j<=cnt;j++) f[tot][j]=0;
	for (int i=1;i<=tot;i++) w[i]=i;
	assert(tot<=999),assert(cnt<=999);
	for (int i=1;i<=n;i++)
	{
		if ((vis[i]&1)==0) continue;
		w[col[i]]=col[p[i]];
	}
	for (int i=l;i<=r;i++)
	{
		if (q[i][0]==1)
		{
			calc(i,g[q[i][1]-1],-1);
			calc(i,g[q[i][2]],1);
			ans[i]+=v[q[i][2]]-v[q[i][1]-1];
		}
		else if (q[i][0]==2)
		{
			timttt++;
			change(col[q[i][1]],q[i][2]);
		}
		else
		{
			int x=q[i][1],y=q[i][2];
			swap(p[x],p[y]);
			w[col[x]]=col[p[x]];
			w[col[y]]=col[p[y]];
		}
	}
	
	for (int i=1;i<=n;i++) a[i]=add[col[i]];
	for (int i=1;i<=n;i++) a[i]+=a[i-1];
	for (int i=1;i<=n;i++) v[i]+=a[i];
}
 
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) v[i]=v[i-1]+a[i];
	for (int i=1;i<=n;i++) p[i]=read();
	memset(ans,0,sizeof(ans));
	m=read();
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<3;j++) q[i][j]=read();
	}
	int l=1,r=0;
	while (1)
	{
		l=r+1,r=l+B-1;
		if (r>m) r=m;
		work(l,r);
		if (r==m) break;
	}
	for (int i=1;i<=m;i++)
	{
		if (q[i][0]==1) printf("%lld\n",ans[i]);
	}
	return 0;
}