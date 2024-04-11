#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod=998244353;
int n,m,f[1000001],x,y,inv[1000001],sx1,sx2,sy1,sy2,ans,sf,t[1000001],tot;

struct node
{
	int val,x,y;
}a[1000001];

int read()
{
	int p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

int quickmi(int a,int b)
{
	int t=1;
	while (b)
	{
		if (b&1) t=1ll*t*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return t;
}

bool cmp(node a,node b) {return a.val>b.val;}

int add(int x,int val)
{
	for (; x<=tot; x+=(x&-x)) t[x]=(t[x]+val)%mod;
}

int ask(int x)
{
	int ans=0;
	for (; x; x-=(x&-x)) ans=(ans+t[x])%mod;
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m); tot=0;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=m; j++) a[++tot].val=read(),a[tot].x=i,a[tot].y=j;
	sort(a+1,a+1+tot,cmp);
	memset(t,0,sizeof(t));
	scanf("%d%d",&x,&y);
	for (int i=1; i<=n*m; i++) inv[i]=quickmi(i,mod-2);
	sx1=sx2=sy1=sy2=0; sf=0;
	memset(f,0,sizeof(f)); ans=0;
	for (int i=1; i<=tot; i++)
	{
		int l=i;
		while (i<tot&&a[i].val==a[i+1].val) i++;
		int r=i;
		for (int j=l; j<=r; j++) 
			f[j]=((1ll*ask(j)*a[j].x%mod*a[j].x-2ll*a[j].x*sx1+sx2+1ll*ask(j)*a[j].y%mod*a[j].y-2ll*a[j].y*sy1+sy2)+sf)%mod;
		if (i==tot)	
		{
			for (int j=l; j<=r; j++) ans=(ans+f[j])%mod;
			printf("%d\n",(ans+mod)%mod); return 0;
		}
		for (int j=l; j<=r; j++)
			if (a[j].x==x&&a[j].y==y)
			{
				sx1=(sx1+1ll*a[j].x*inv[tot-i])%mod,
				sx2=(sx2+1ll*a[j].x*a[j].x%mod*inv[tot-i])%mod,
				sy1=(sy1+1ll*a[j].y*inv[tot-i])%mod,
				sy2=(sy2+1ll*a[j].y*a[j].y%mod*inv[tot-i])%mod,
				sf=(sf+1ll*inv[tot-i]*f[j])%mod;
			} else
			sx1=(sx1+1ll*ask(j)*a[j].x%mod*inv[tot-i])%mod,
			sx2=(sx2+1ll*a[j].x*ask(j)%mod*a[j].x%mod*inv[tot-i])%mod,
			sy1=(sy1+1ll*a[j].y*ask(j)%mod*inv[tot-i])%mod,
			sy2=(sy2+1ll*a[j].y*ask(j)%mod*a[j].y%mod*inv[tot-i])%mod,
			sf=(sf+1ll*inv[tot-i]*f[j])%mod;
		for (int j=l; j<=r; j++)
			if (a[j].x==x&&a[j].y==y) add(r+1,inv[tot-i]);
			else add(r+1,1ll*ask(j)*inv[tot-i]%mod);
	}
	return 0;
}