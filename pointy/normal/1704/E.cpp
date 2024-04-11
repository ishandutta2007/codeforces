// Author: Little09
// Problem: E. Count Seconds
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll a[N];

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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

int d[N],dfn[N],cnt,f[N];
vector<int>t[N];
inline void add(int x,int y)
{
	t[x].push_back(y);
	d[y]++;
}
queue<int>q;
void topo()
{
	while (!q.empty()) q.pop();
	for (int i=1;i<=n;i++)
	{
		if (d[i]==0) q.push(i);
	}
	cnt=0;
	while (!q.empty())
	{
		int u=q.front();
		dfn[++cnt]=u;
		q.pop();
		for (int i:t[u])
		{
			d[i]--;
			if (d[i]==0) q.push(i);
		}
	}
}

bool check()
{
	for (int i=1;i<=n;i++)
	{
		if (a[i]>0) return 1;
	}
	return 0;
}

void work()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(),d[i]=0;
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		add(x,y);
	}
	topo();
	ll ans=0;
	while (1)
	{
		if (check()==0)
		{
			printf("%lld\n",ans);
			return;
		}
		for (int i=1;i<=n;i++) f[i]=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]>0)
			{
				f[i]=1;
				a[i]--;
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (f[i]>0)
			{
				for (int j:t[i]) a[j]++;
			}
		}
		ans++;
		if (ans>n) break;
	}
	for (int i=1;i<=n;i++) a[i]%=mod;
	for (int i=1;i<=n;i++)
	{
		for (int j:t[dfn[i]]) a[j]=(a[j]+a[dfn[i]])%mod;
	}
	ans=(ans+a[dfn[n]])%mod;
	printf("%lld\n",ans);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}