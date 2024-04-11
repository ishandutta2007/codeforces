#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define int long long
#define pb push_back
#define YES puts("YES")
#define NO puts("NO")
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=998244353;
const int M=6e5+10;
int n,k,l[M],r[M],pp[M],cnt,t1[M],fac[M],ifac[M];
map<int,int>t;

struct node
{
	int l,r;
}a[M];
bool cmp(node a,node b){return a.l<b.l;}
int c[M];
int lowbit(int x){return x&(-x);}
void add(int x)
{
	for (int i=x;i<=cnt;i+=lowbit(i))
		c[i]++;
}
int query(int x)
{
	int res=0;
	for (int i=x;i>=1;i-=lowbit(i))res+=c[i];
	return res;
}

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}
int inv(int x){return poww(x,Mod-2);}
void init(int n)
{
	fac[0]=ifac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%Mod,
		ifac[i]=inv(fac[i]);
}
int C(int m,int n){return m<n?0ll:fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;}

signed main()
{
	n=read(),k=read();init(2*n);
	for(int i=1;i<=n;i++)
		l[i]=pp[i*2-1]=read(),r[i]=pp[i*2]=read();
	sort(pp+1,pp+1+2*n);
	for (int i=1;i<=n*2;i++)
		if (pp[i]!=pp[i-1])t[pp[i]]=++cnt;
	for (int i=1;i<=n;i++)
		a[i].l=t[l[i]],a[i].r=t[r[i]],t1[a[i].l]++;
	sort(a+1,a+1+n,cmp);int ans=0;
	for (int i=1;i<=n;i++)
	{
		add(a[i].r);
		if (a[i].l==a[i+1].l)continue;
		int sum=i-query(a[i].l-1);
		ans=(ans+C(sum,k)-C(sum-t1[a[i].l],k)+Mod)%Mod;
	}cout<<ans<<endl;
	return 0;
}