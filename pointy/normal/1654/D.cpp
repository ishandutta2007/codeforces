// By: Little09
// Problem: D. Potion Brewing Class
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N];

int t[N],nxt[N],h[N],cnt,v[N],w[N],p[N];



void add(int x,int y,int z,int l)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	w[cnt]=z,v[cnt]=l;
	h[x]=cnt;
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

namespace INT
{
	const int MAXN=N-5;
	int mu[N],phi[N];
	int v[N],cnt;
	void init() 
	{
	    v[1]=mu[1]=phi[1]=1;
	    cnt=0;
	    for (int i=2;i<=MAXN;++i) 
		{
	        if (!v[i]) p[++cnt]=i,mu[i]=-1,phi[i]=i-1;
	        for (int j=1;j<=cnt&&i*p[j]<=MAXN;++j) 
			{
	            v[i*p[j]]=1;
	            if (i%p[j]) mu[i*p[j]]=-mu[i],phi[i*p[j]]=phi[i]*phi[p[j]];
	            else 
				{ 
					mu[i*p[j]]=0,phi[i*p[j]]=phi[i]*p[j]; 
					break; 
				}
	        }
	    }
	    for (int i=1;i<=MAXN;++i) mu[i]+=mu[i-1],phi[i]+=phi[i-1];
	}	
}



void add(int x,int y)
{
	int tot=INT::cnt,z=sqrt(x);
	for (int i=1;i<=tot;i++)
	{
		if (p[i]>z) break;
		while (x%p[i]==0)
		{
			a[p[i]]+=y;
			x/=p[i];
			b[p[i]]=min(b[p[i]],a[p[i]]);
		}
	}
	if (x!=1) a[x]+=y,b[x]=min(b[x],a[x]);
}

ll ans,res;


void dfs(int x,int fa)
{
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]==fa) continue;
		add(v[i],1),add(w[i],-1);
		dfs(t[i],x);
		add(v[i],-1),add(w[i],1);
	}
}

ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}


void dfs2(int x,int fa,ll y)
{
	ans=(ans+y)%mod;
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]==fa) continue;
		dfs2(t[i],x,y*v[i]%mod*ksm(w[i],mod-2)%mod);
	}
}
void work()
{
	n=read();
	cnt=0;
	for (int i=0;i<=2*n;i++)
	{
		t[i]=0,nxt[i]=0,h[i]=0;
		v[i]=0,w[i]=0,a[i]=0,b[i]=0;
	}
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read(),z=read(),l=read();
		int o=__gcd(z,l);
		z/=o,l/=o;
		add(x,y,z,l),add(y,x,l,z);
	}
	dfs(1,0);
	ans=0,res=1;
	for (int i=1;i<=n;i++) res=res*ksm(i,-b[i])%mod;
	dfs2(1,0,res);
	cout << ans << endl;
}

int main()
{
	INT::init();
	int T=read();
	while (T--) work();
	return 0;
}