#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

bool get(){static int x;scanf("%1d",&x);return x;}
ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool e[N][N],f[N];
int siz[N],deg[N],ans1=N,ans2=0,n;
bool check()
{
	static int tmp[N];
	for (int i=1;i<=n;i++) tmp[i]=siz[i];
	sort(tmp+1,tmp+1+n);
	for (int i=1,sum=0;i<n;i++)
	if ((sum+=tmp[i])==i*(i-1)/2) return 0;
	return 1;
}
void dfs(int now,int tot,int k)
{
	if (now>n)
	{
		memset(siz,0,sizeof(siz));
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (i!=j) siz[i]+=e[i][j]^f[i]^f[j];
		if (!check()) return;
		if (tot<ans1) ans1=tot,ans2=k;
		else if (tot==ans1) ans2+=k;
		return;
	}
	f[now]=0,dfs(now+1,tot,k);
	f[now]=1,dfs(now+1,tot+1,k*(tot+1));
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	deg[i]+=e[i][j]=get();
	if (n<7)
	{
		dfs(1,0,1);
		if (ans1<N) print(ans1,' '),print(ans2);
			   else puts("-1");
	}
	else
	{
		for (int i=1;i<=n;i++) siz[i]=deg[i];
		if (check()) return puts("0 1"),0;
		print(1,' ');
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++) siz[j]=deg[j];
			for (int j=1;j<=n;j++)
			if (i!=j)
			{
				if (e[i][j]) siz[i]--,siz[j]++;
						else siz[i]++,siz[j]--;
			}
			ans2+=check();
		}
		print(ans2);
	}
	
	return 0;
}