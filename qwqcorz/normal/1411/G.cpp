#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=512;
const int p=998244353;
const int inv2=(p+1)/2;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	for (;b;a=1LL*a*a%p,b/=2) if (b&1) ret=1LL*ret*a%p;
	return ret;
}
void fwt(int *a,int type)
{
	for (int mid=1;mid<M;mid*=2)
	for (int k=0,len=mid*2;k<M;k+=len)
	for (int i=k;i<k+mid;i++)
	{
		int x=a[i],y=a[i+mid];
		a[i]=(x+y)%p;
		a[i+mid]=(x-y+p)%p;
		if (type<0)
			a[i]=1LL*a[i]*inv2%p,
			a[i+mid]=1LL*a[i+mid]*inv2%p;
	}
}
int deg[N],sg[N];
vector<int>e[N],ne[N];
bool vis[M];
void get(int x)
{
	for (int to:e[x]) vis[sg[to]]=1;
	while (vis[sg[x]]) sg[x]++;
	for (int to:e[x]) vis[sg[to]]=0;
}
void getSG(int n)
{
	queue<int>q;
	for (int i=1;i<=n;i++) if (!deg[i]) q.push(i),sg[i]=0;
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		for (int to:ne[now]) if (!--deg[to]) q.push(to),get(to);
	}
}
int tot[M];
signed main()
{
	int n=read(),m=read(),iv=power(n+1,p-2);
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		ne[v].push_back(u);
		deg[u]++;
	}
	getSG(n);
	tot[0]=1;
	for (int i=1;i<=n;i++) tot[sg[i]]=(tot[sg[i]]-iv+p)%p;
	fwt(tot,1);
	for (int i=0;i<M;i++) tot[i]=power(tot[i],p-2);
	fwt(tot,-1);
	print((1-1LL*iv*tot[0]%p+p)%p);
	
	return 0;
}