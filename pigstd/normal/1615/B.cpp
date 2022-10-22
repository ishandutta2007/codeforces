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

const int M=2e5+10;
const int N=2e5;
int sum[M][20];

signed main()
{
	for (int i=1;i<=N;i++)
		for (int j=0;j<=19;j++)
			if ((i>>j)&1^1)sum[i][j]++;
	for (int i=0;i<=19;i++)for (int j=1;j<=N;j++)sum[j][i]+=sum[j-1][i];
	WT
	{
		int l=read(),r=read();
		int ans=1e18;
		for (int i=0;i<=19;i++)ckmin(ans,sum[r][i]-sum[l-1][i]);
		printf("%lld\n",ans);
	}
	return 0;
}