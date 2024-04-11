#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=260;
const int N=70;
int n,m,U[M],V[M],W[M],f[N][N],a[M*N][M],cnt,ans[M];

void solve()
{
	for (int i=1;i<=cnt;i++)for (int j=1;j<=m+1;j++)a[i][j]=ans[j]=0;cnt=0; 
	n=read(),m=read();
//	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)f[i][i]=0;
	memset(f,0,sizeof(f));
	for (int i=1;i<=m;i++)
		U[i]=read(),V[i]=read(),W[i]=read(),
		f[U[i]][V[i]]=f[V[i]][U[i]]=i;
	for (int i=1;i<=n;i++)
		for (int j=1+i;j<=n;j++)
			for (int k=1+j;k<=n;k++)
			{
				if (!f[i][j]||!f[i][k]||!f[j][k])continue;
				int w1=f[i][j],w2=f[i][k],w3=f[j][k];
				if (W[w1]!=-1&&W[w2]!=-1&&W[w3]!=-1)
				{
					if ((W[w1]+W[w2]+W[w3])%3)
						return puts("-1"),void();
				}
				else
				{
					cnt++;
					if (W[w1]==-1)a[cnt][w1]=1;else a[cnt][m+1]+=3-W[w1];
					if (W[w2]==-1)a[cnt][w2]=1;else a[cnt][m+1]+=3-W[w2];
					if (W[w3]==-1)a[cnt][w3]=1;else a[cnt][m+1]+=3-W[w3];
					a[cnt][m+1]%=3;
				}
			}
	int L=1;
	for (int i=1;i<=m;i++)
	{
		for (int j=L;j<=cnt;j++)
			if (a[j][i]){swap(a[j],a[L]);break;}
		if (!a[L][i])continue;
		for (int j=m+1;j>=i;j--)a[L][j]=a[L][j]*a[L][i]%3;
		for (int j=L+1;j<=cnt;j++)
			if (a[j][i])
			{
				for (int k=m+1;k>=i;k--)
					a[j][k]=(a[j][k]-a[j][i]*a[L][k]%3+3)%3;
				assert(!a[j][i]);
			}
		L++;
	}
	for (int i=L;i<=cnt;i++)
		if (a[i][m+1])return puts("-1"),void();
	for (int i=L-1;i>=1;i--)
	{
		int pos=0;
		for (int j=1;j<=m;j++)
			if (a[i][j]){pos=j;break;}
		ans[pos]=a[i][m+1];
		for (int j=pos+1;j<=m;j++)
			ans[pos]=(ans[pos]-a[i][j]*ans[j]+30)%3;
	}
	for (int i=1;i<=m;i++)
		if (W[i]==-1)cout<<(ans[i]==0?3:ans[i])<<' ';
		else cout<<W[i]<<' ';puts("");
//	if (cnt>=N*M)cout<<cnt<<endl;
}

signed main()
{
	WT solve();
	return 0;
}
/*
1
3 3
1 2 1
2 3 1
3 1 -1
*/