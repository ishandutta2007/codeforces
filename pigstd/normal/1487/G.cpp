#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int Mod=998244353;
const int M=410;
int n,c[30],f[2][M][M][3][3],f2[2][M][3][3],g1[M][M],g2[M];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void add(int &u,int k){u=(u+k>=Mod?u+k-Mod:u+k);}

signed main()
{
	n=read();
	for (int i=1;i<=26;i++)c[i]=read();
	f[0][0][0][0][0]=1;
	for (int i=0;i<n;i++)
	{
		memset(f[(i&1)^1],0,sizeof(f[(i&1)^1]));
		for (int j=0;j<=i;j++)
			for (int k=0;k+j<=i;k++)
				for (int w1=0;w1<3;w1++)
					for (int w2=0;w2<3;w2++)
					{
						int val=f[i&1][j][k][w1][w2];
						if (val==0)continue;
						add(f[(i&1)^1][j+1][k][w2][1],(w1==1?0:1)*val),
						add(f[(i&1)^1][j][k+1][w2][2],(w1==2?0:1)*val),
						add(f[(i&1)^1][j][k][w2][0],((w1==0&&i>=2)?23:24)*val%Mod);
					}
	}f2[0][0][0][0]=1;
	int res=26*26*poww(25,n-2)%Mod;
//	cout<<res<<endl;
	for (int i=0;i<n;i++)
	{
		memset(f2[(i&1)^1],0,sizeof(f2[(i&1)^1]));
		for (int j=0;j<=i;j++)
			for (int w1=0;w1<2;w1++)
				for (int w2=0;w2<2;w2++)
				{
					int val=f2[i&1][j][w1][w2];
					if (val==0)continue;
					add(f2[(i&1)^1][j+1][w2][1],(w1==1?0:1)*val),
					add(f2[(i&1)^1][j][w2][0],((w1==0&&i>=2)?24:25)*val%Mod);
				}
	}
	for (int i=0;i<=n;i++)
		for (int w1=0;w1<3;w1++)
			for (int w2=0;w2<3;w2++)add(g2[i],f2[n&1][i][w1][w2]);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int w1=0;w1<3;w1++)
				for (int w2=0;w2<3;w2++)add(g1[i][j],f[n&1][i][j][w1][w2]);
	for (int i=1;i<=26;i++)
		for (int j=c[i]+1;j<=n;j++)add(res,Mod-g2[j]);//,cout<<j<<' '<<g2[j]<<endl;
//	cout<<res<<endl;
	for (int i=1;i<=26;i++)
		for (int j=i+1;j<=26;j++)
			for (int w1=c[i]+1;w1<=n;w1++)
				for (int w2=c[j]+1;w2<=n;w2++)
					add(res,g1[w1][w2]);
	cout<<res<<endl;
	return 0;
}
/*
sb /tuu 
*/