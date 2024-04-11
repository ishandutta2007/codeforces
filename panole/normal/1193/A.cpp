#include<bits/stdc++.h>
using namespace std;

const int N=(1<<18|3),mod=998244353;
const long long Mod=1ll*mod*mod;
int n,m,f[N],g[N],h[N],a[21][21],v[21][N],x,y,lo[N],t[N],tn,nw[N];
long long G[N];

void add(int &x,int y) {x=(x+y>=mod?x+y-mod:x+y);}
void Add(long long &x,long long y) {x=(x+y>=Mod?x+y-Mod:x+y);}
void mns(int &x,int y) {x=(x<y?x-y+mod:x-y);}
void Mns(long long &x,long long y) {x=(x<y?x-y+Mod:x-y);}

int main()
{
	for (int i=0; i<18; i++) lo[1<<i]=i+1;
	scanf("%d%d",&n,&m);
	if (m==0) return puts("0"),0;
	for (int i=1; i<=m; i++) 
	{
		scanf("%d%d",&x,&y),a[x][y]=1;
		v[y][1<<x-1]=1;
	}
	for (int i=1; i<=n; i++)
	{
		v[i][0]=0;
		for (int k=1; k<(1<<n); k++) 
		{
			v[i][k]=v[i][k&-k];
			add(v[i][k],v[i][k^(k&-k)]);
		}
	}
	h[0]=mod-1;
	for (int i=1,I,nw; i<(1<<n); i++)
		if (h[I=(i^(i&-i))])
		{
			nw=lo[i&-i];
			bool bo=1;
			for (int j=0; j<n; j++)
				if ((I>>j&1)&&(a[j+1][nw]||a[nw][j+1])) {bo=0; break;}
			if (bo) h[i]=mod-h[I]; else h[i]=0;
		}
	f[0]=1,G[0]=0;
	for (int i=0; i<(1<<n); i++)
		if (f[i])
		{
			g[i]=G[i]%mod,tn=0;
			for (int I=(i^((1<<n)-1)),j=I; j; j=(j-1)&I)
				if (h[j]) t[++tn]=j;
			for (int I=tn,j; I; I--) 
			{
				j=t[I],nw[j]=nw[j^(j&-j)];
				add(nw[j],v[lo[j&-j]][i]);
				if (h[j]==1)
				{
					add(f[i|j],f[i]);
					Add(G[i|j],g[i]);
					Add(G[i|j],1ll*f[i]*nw[j]);
				} else
				{
					mns(f[i|j],f[i]);
					Mns(G[i|j],g[i]);
					Mns(G[i|j],1ll*f[i]*nw[j]);
				}
			}
		}
	printf("%d\n",g[(1<<n)-1]);
	return 0;
}