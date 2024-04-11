#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool vis[N];
vector<int>fac[N];
void ysgs(int n)
{
	for (int i=2;i<=n;i++) if (!vis[i])
	for (int j=i;j<=n;j+=i) vis[j]=1,fac[j].push_back(i);
}
int a[N],nxt[N][20],lst[N];

signed main()
{
	ysgs(1e5);
	memset(lst,0x3f,sizeof(lst));
	int n=read(),Q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=n,j=n+1;i>=1;i--)
	{
		for (int k:fac[a[i]]) j=min(j,lst[k]),lst[k]=i;
		nxt[i][0]=j;
	}
	nxt[n+1][0]=n+1;
	for (int j=1;j<20;j++)
	for (int i=1;i<=n+1;i++)
	nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	for (int i=1;i<=Q;i++)
	{
		int l=read(),r=read(),ans=1;
		for (int j=19;j>=0;j--) if (nxt[l][j]<=r) l=nxt[l][j],ans+=1<<j;
		print(ans);
	}
	
	return 0;
}