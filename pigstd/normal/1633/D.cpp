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

const int M=1e3+10;
int n,k,w[M],dp[M*20],c[M],b[M];

void init()
{
	memset(w,0x3f,sizeof(w));w[1]=0;
	for (int i=1;i<=1000;i++)
		for (int j=1;j<=i;j++)
			if (i+i/j<=1000)
				ckmin(w[i+i/j],w[i]+1);
}

signed main()
{
//	freopen("2.out","w",stdout); 
	init();
//	for (int i=1;i<=1000;i++)cout<<w[i]<<' '; 
//	return 0; 
	WT
	{
		n=read(),k=min(n*20,read());int cnt=0;
		for (int i=1;i<=n;i++)b[i]=w[read()],cnt+=b[i];//,cout<<b[i]<<' ';puts("");
		for (int i=1;i<=n;i++)c[i]=read();
		memset(dp,0,sizeof(dp));int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=k;j>=b[i];j--)ckmax(dp[j],dp[j-b[i]]+c[i]),ckmax(ans,dp[j]);
//		int ans=0;
//		for (int i=1;i<=k;i++)ckmax(ans,dp[i]);
		cout<<ans<<'\n';
	}
	return 0;
}