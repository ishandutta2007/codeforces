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

const int M=60;
const int P=55*5;
int n,a[M],dp[M][M*10][M*10];
string s;

void ckmin(int &a,int b){a=(a>b?b:a);}

signed main()
{
	cin>>s;n=s.size()+2;
	for (int i=3;i<=n;i++)a[i]=s[i-3]-'0';
	memset(dp,0x3f,sizeof(dp));
	dp[0][P][P]=0;
	for (int i=1;i<=n;i++)
		for (int j=-5*i;j<=5*i;j++)
			for (int k=-5*i;k<=5*i;k++)
				for (int w=-10;w<=10;w++)
				{
//					if (dp[i-1][j+P][k+P]==dp[0][0][0])continue;
					int x=k*10+j+w-a[i];
					if (x<=5*i&&x>=-5*i)
						ckmin(dp[i][j+P+w][x+P],dp[i-1][j+P][k+P]+abs(w)*(n-i+1));
				}int ans=1e18;
	for (int j=-5*n;j<=5*n;j++)ckmin(ans,dp[n][j+P][P]);
	cout<<ans<<endl;
	return 0;
}