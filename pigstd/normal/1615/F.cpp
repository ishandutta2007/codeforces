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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int Mod=1e9+7; 
const int M=2010;
const int N=2000;
int n,a1[M],a2[M],C[M][M],s1[M],s2[M],s3[M],s4[M];
string S1,S2;

int calc(int i,int a,int j,int b)
{
	if (a+i-j>=0&&a+i-j<=a+b)return C[a+b][a+i-j];
	else return 0;
}

void solve()
{
	n=read();cin>>S1>>S2;int res=0;
	for (int i=1;i<=n;i++)
	{
		a1[i]=S1[i-1]=='?'?-1:S1[i-1]-'0',
		a2[i]=S2[i-1]=='?'?-1:S2[i-1]-'0';
		if (a1[i]!=-1)a1[i]^=i&1;
		if (a2[i]!=-1)a2[i]^=i&1;
		s1[i]=s1[i-1]+(a1[i]==-1),
		s2[i]=s2[i-1]+(a1[i]==0),
		s3[i]=s3[i-1]+(a2[i]==-1),
		s4[i]=s4[i-1]+(a2[i]==0);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (a1[i]==1||a2[j]==1)continue;
			res=(res+abs(i-j)*calc(s2[i-1],s1[i-1],s4[j-1],s3[j-1])%Mod*
			calc(s2[n]-s2[i],s1[n]-s1[i],s4[n]-s4[j],s3[n]-s3[j]))%Mod;
		}
	printf("%lld\n",res);
}

void init(int n)
{
	for (int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
}

signed main()
{
	init(2000);
	WT solve();
	return 0;
}