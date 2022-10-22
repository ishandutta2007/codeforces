//AFO countdown:10 Days
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
const int base=27;
const int M=2e5+10;
const int N=30;
int n,m,a[M],sum[N][M],f[N][M];
string s;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

signed main()
{
	n=read(),m=read();
	cin>>s;memset(f,0x2f,sizeof(f));
	for (int i=1;i<=n;i++)
		a[i]=s[i-1]-'a'+1,sum[a[i]][i]=1,f[a[i]][i]=i;
	for (int i=1;i<=26;i++)
		for (int j=1;j<=n;j++)
			sum[i][j]=(sum[i][j-1]*base+sum[i][j]+1)%Mod;
	for (int i=1;i<=26;i++)
		for (int j=n;j>=1;j--)
			f[i][j]=min(f[i][j],f[i][j+1]);
	while(m--)
	{
		int l=read(),r=read(),k=read(),F=1;
		for (int i=1;i<=26;i++)
		{
			int x=f[i][l];if (x>=l+k)continue;
			int y=a[x+r-l];//i -> y
			int hash1=(sum[i][l+k-1]-sum[i][l-1]*poww(base,k)%Mod+Mod)%Mod;
			int hash2=(sum[y][r+k-1]-sum[y][r-1]*poww(base,k)%Mod+Mod)%Mod;
//			cout<<i<<' '<<hash1<<' '<<hash2<<endl;
			if (hash1!=hash2){NO F=0;break;}
		}
		if (F)YES
	}
	return 0;
}