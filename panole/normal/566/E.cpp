#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v[1001];
vector<int> t[1001];
unsigned int f[1001][32],nw[32],g[1001][32],F[1001][32],G[1001][32];
int n,d[1001],c[1<<16],cnt,x,tn,A[1001],An,fa[1001],mi,mii,D[1001];
bool bo[1001],Bo[1001],boo;

bool cmp(int a,int b) {return d[a]<d[b];}
void del(int j) {for (int i=1; i<=n; i++) if ((f[j][i>>5]>>(i&31))&1) d[i]--;}
void print(int x,int y)
{
	printf("%d %d\n",x,y);
	g[x][y>>5]|=(1ll<<(y&31));
	g[y][x>>5]|=(1ll<<(x&31));
}

void dfs(int x)
{
	Bo[x]=0;
	if (d[x]==3)
	{
		int po;
		for (int i=1; i<=n; i++)
			if (bo[i]&&((f[i][x>>5]>>(x&31))&1))
			{
				int cnt=0;
				for (int j=0; j<32; j++) cnt+=c[f[i][j]&nw[j]&65535]+c[(f[i][j]&nw[j])>>16];
				if (cnt==3) {po=i; break;}
			}
		int po1=0,po2=0;
		for (int i=1; i<=n; i++)
			if (i!=x&&((f[po][i>>5]>>(i&31))&1)&&((nw[i>>5]>>(i&31))&1))
				{if (!po1) po1=i; else po2=i;}
		del(po); bo[po]=0; nw[x>>5]^=(1ll<<(x&31));
		if (!fa[x]) 
		{
			if ((G[po1][x>>5]>>(x&31))&1) fa[x]=po1; else
			if ((G[po2][x>>5]>>(x&31))&1) fa[x]=po2; else
			if (D[po1]<D[po2]) fa[x]=po1; else fa[x]=po2;
			print(x,fa[x]);
		}
		print(po1,po2);
		if (fa[x]==po1) fa[po1]=po2; else fa[po2]=po1;
		if (fa[x]) dfs(fa[x]);
		return;
	}
	mi=(1e9); mii=0;
	for (int i=1; i<=n; i++)
		if (bo[i]&&((f[i][x>>5]>>(x&31))&1)&&((f[i][fa[x]>>5]>>(fa[x]&31))&1))
		{
			int cnt=0;
			for (int j=0; j<32; j++) cnt+=c[f[i][j]&nw[j]&65535]+c[(f[i][j]&nw[j])>>16];
			if (cnt<mi) mi=cnt,mii=i;
		}
	if (mii)
	{
		for (int i=0; i<32; i++) G[fa[x]][i]|=f[mii][i]; 
		del(mii),bo[mii]=0;
	}
	nw[x>>5]^=(1ll<<(x&31));
}

int main()
{
	for (int i=0; i<(1<<16); i++)
	{
		c[i]=0;
		for (int j=0; j<16; j++)
			if ((i>>j)&1) c[i]++;
	}
	scanf("%d",&n);
	memset(d,0,sizeof(d));
	for (int i=1; i<=n; i++)
		for (int j=0; j<32; j++) f[i][j]=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&cnt); v[i].clear(); t[i].clear();
		for (int j=1; j<=cnt; j++) scanf("%d",&x),d[x]++,f[i][x>>5]|=(1ll<<(x&31));
	}
	cnt=0;
	for (int j=0; j<32; j++)
	{
		nw[j]=0;
		for (int k=0; k<32; k++) nw[j]|=(1ll<<k);
	}
	memset(bo,1,sizeof(bo));
	memset(Bo,1,sizeof(Bo));
	for (int i=1; i<=n; i++)
		if (bo[i])
		{
			tn=0;
			for (int j=1; j<=n; j++)
			{
				boo=1;
				for (int k=0; k<32; k++)
					if (f[i][k]^f[j][k]) {boo=0; break;}
				if (boo) continue;
				for (int k=0; k<32; k++)
					if ((f[i][k]&f[j][k])!=f[j][k]) {boo=1; break;}
				if (!boo) {tn=-1; break;}
			}
			if (tn==-1) continue;
			for (int j=i+1; j<=n; j++)
				if (bo[j])
				{
					boo=1;
					for (int k=0; k<32; k++)
						if (f[i][k]^f[j][k]) {boo=0; break;}
					if (boo) tn++,bo[j]=0;
				}
			if (tn)
			{
				if (tn==n-1)
				{
					for (int i=2; i<=n; i++) print(1,i);
					return 0;
				}
				An=0;
				for (int j=1; j<=n; j++)
					if ((f[i][j>>5]>>(j&31))&1) A[++An]=j;
				sort(A+1,A+1+An,cmp); cnt++;
				for (int j=1; j<=tn; j++)
					nw[A[j]>>5]^=(1ll<<(A[j]&31)),t[cnt].push_back(A[j]);
				for (int j=0; j<32; j++) F[cnt][j]=0;
				for (int j=tn+1; j<=An; j++) 
					F[cnt][A[j]>>5]|=(1ll<<(A[j]&31)),v[A[j]].push_back(cnt);
			}
		}
	for (int i=1; i<=n; i++) if (!bo[i]) del(i);
	memset(fa,0,sizeof(fa));
	for (int i=1; i<=n; i++)
		for (int j=0; j<32; j++) g[i][j]=G[i][j]=0;
	for (int j=1; j<=n; j++)
	{
		for (int i=1; i<=n; i++) D[i]=d[i];
		for (int i=1; i<=n; i++) 
			if (((nw[i>>5]>>(i&31))&1)&&Bo[i]&&D[i]==3) dfs(i);
	}
	int po1=0,po2=0;
	for (int i=1; i<=n; i++)
		if (((nw[i>>5]>>(i&31))&1)&&d[i]==2) {if (!po1) po1=i; else po2=i;}
	if (po2) print(po1,po2);
	memset(bo,1,sizeof(bo));
	for (int i=1,sz; i<=n; i++)
	{
		sz=v[i].size();
		g[i][i>>5]|=(1ll<<(i&31));
		for (int j=0; j<sz; j++)
			if (bo[v[i][j]])
			{
				x=v[i][j]; boo=1;
				for (int k=0; k<32; k++)
					if (F[x][k]!=g[i][k]) {boo=0; break;}
				if (boo)
				{
					int siz=t[x].size(); bo[x]=0;
					for (int k=0; k<siz; k++) print(i,t[x][k]);
					break;
				}
			}
	}
	return 0;
}