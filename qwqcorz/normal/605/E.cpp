#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool vis[N];
double p[N][N],f[N],mul[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) p[i][j]=read()/100.0;
	for (int i=1;i<n;i++) f[i]=mul[i]=1;
	for (int k=1;k<=n;k++)
	{
		int now=0;
		for (int i=1;i<=n;i++) if (!vis[i]) if (!now||f[i]*1/(1-mul[i])<=f[now]*1/(1-mul[now])) now=i;
		if (now<n) f[now]*=1/(1-mul[now]);
		vis[now]=1;
		for (int i=1;i<=n;i++)
		if (!vis[i]) f[i]+=f[now]*p[i][now]*mul[i],mul[i]*=1-p[i][now];
	}
	printf("%.10lf\n",f[1]);
	
	return 0;
}