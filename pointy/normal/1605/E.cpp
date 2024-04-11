// By: Little09
// Problem: E. Array Equalizer
// Contest: Codeforces - Codeforces Round #754 (Div. 2)
// URL: https://codeforces.ml/contest/1605/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+15;
#define ll long long
#define int ll
ll a[N],b[N],c[N],d[N],tot;
const int MAXN=N-5;
int mu[N],phi[N];
int p[N],v[N],cnt;
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
const int M=2e6+5,MAX=2e6;
int ans[M],n;
int tree[M][2];
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int k,int tp)
{
	for (;x<=MAX;x+=lowbit(x)) tree[x][tp]+=k;
}
int ask(int x,int tp)
{
	int res=0;
	for (;x;x-=lowbit(x)) res+=tree[x][tp];
	return res;
}
void work(int l,int r,int x,int tp)
{
	if (l<=1) l=1;
	if (l>r) return;
	add(l,x,tp);
	if (r>=MAX) r=MAX;
	if (r!=MAX) add(r+1,-x,tp);
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	init();
	b[1]=0;
	for (int i=1;i<=n;i++) c[i]=a[i];
	for (int i=1;i<=n;i++)
	{
		d[i]=b[i]-c[i];
		for (int j=1;i*j<=n;j++)
		{
			c[i*j]+=d[i];
		}
	}
	for (int i=1;i<=n;i++)
	{
		//cout << d[i] << " ";
		if (mu[i]==0) tot+=abs(d[i]);
		else if (mu[i]==1)
		{
			//cout << d[i] << endl;
			work(1,-d[i],-1,0);
			work(1,-d[i],-d[i],1);
			work(-d[i]+1,MAX,1,0);
			work(-d[i]+1,MAX,d[i],1);
		}
		else
		{
			work(1,d[i],-1,0);
			work(1,d[i],d[i],1);
			work(d[i]+1,MAX,1,0);
			work(d[i]+1,MAX,-d[i],1);
		}
	}
	//cout << endl;
	int T=read();
	while (T--)
	{
		ll x=read();
		ll y=ask(x,0),z=ask(x,1);
		ll ans=x*y+z+tot;
		printf("%lld\n",ans);
	}
	return 0;
}