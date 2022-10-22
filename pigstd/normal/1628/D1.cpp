#include<bits/stdc++.h>
#define int long long
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

const int Mod=1e9+7;
const int inv2=(Mod+1)/2;
const int M=2010;
int n,dp[M][M];

signed main()
{
	dp[1][1]=1;
	for (int i=2;i<=2000;i++)
	{ 
		for (int j=1;j<i;j++)dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*inv2%Mod;
		dp[i][i]=i;
	} 
	WT
	{
		int n=read(),m=read(),k=read();
		cout<<dp[n][m]*k%Mod<<'\n';
	}
	return 0;
}
/*
dp[i][j] 

dp[1][0]=0,
dp[1][1]=1,

dp[i][j] = max(min(dp[i-1][j-1]+x,dp[i-1][j]-x))
 dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]) /2 
*/