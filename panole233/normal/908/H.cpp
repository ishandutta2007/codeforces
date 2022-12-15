#include<cstdio>
#include<cstring>

const long long mod=1000000007ll;

long long f[8388608],ff[8388608],xx,c[8388608];
int n,a[48][48],fa[48],p,q,num[48],x,y,cnt,bel[48],ans,k;
bool b[48][48],bo;
char s[50];

int ask(int x) {return fa[x]==x?x:fa[x]=ask(fa[x]);}

void Dfs(int x,int y)
{
	if (x==-1) {c[y]=1; return;}
	Dfs(x-1,y-(1<<x)); Dfs(x-1,y);
	for (int i=y-(1<<x)+1; i<=y; i++) c[i]=-c[i];
}

void dfs(int x,int nw)
{
	if (x==cnt+1) {f[nw]=1; return;}
	bo=1;
	for (int i=1; i<x; i++)
		if (nw&(1<<(i-1)))
			if (!b[i][x]) {bo=0; break;}
	if (bo) dfs(x+1,nw|(1<<(x-1)));
	dfs(x+1,nw);
}

void FWT(int n)
{
	for (int d=1; d<n; d<<=1)
		for (int m=(d<<1),i=0; i<n; i+=m)
			for (int j=0; j<d; j++)
			{
				long long x=f[i+j],y=f[i+j+d];
				f[i+j+d]=(x+y)%mod;
			}
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s",&s);
		for (int j=1; j<=n; j++)
			if (s[j-1]=='A') a[i][j]=1; else
			if (s[j-1]=='O') a[i][j]=2; else
			if (s[j-1]=='X') a[i][j]=3;
	}
	for (int i=1; i<=n; i++) fa[i]=i,num[i]=1;
	for (int i=1; i<n; i++)
		for (int j=i+1; j<=n; j++)	
			if (a[i][j]==1)
			{
				p=ask(i); q=ask(j);
				if (p!=q) fa[p]=q,num[q]+=num[p],num[p]=0;
			}
	cnt=0;
	for (int i=1; i<=n; i++)
		if (fa[i]==i&&num[i]>1) bel[i]=++cnt;
	if (!cnt) {printf("%d\n",n-1); return 0;}
	memset(b,1,sizeof(b));
	for (int i=1; i<n; i++)
		for (int j=i+1; j<=n; j++)
			if (a[i][j]==3)
			{
				p=ask(i); q=ask(j);
				if (p==q) {printf("-1\n"); return 0;}
				b[bel[p]][bel[q]]=b[bel[q]][bel[p]]=0;
			}
	memset(f,0,sizeof(f));
	memset(ff,0,sizeof(ff)); k=(1<<cnt);
	dfs(1,0); Dfs(cnt-1,k-1);
	FWT(k); ans=1;
	for (int i=0; i<k; i++) ff[i]=f[i];
	while (1)
	{
		xx=0;
		for (int i=0; i<k; i++) xx=(xx+c[i]*ff[i])%mod;
		if (xx!=0) {printf("%d\n",ans+n-1); return 0;} 
		ans++;
		for (int i=0; i<k; i++) ff[i]=ff[i]*f[i]%mod;
	}
	return 0;
}