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

const int M=5010;
int n,a[M],ans=1e18;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)
	{
		int now=0,sum=0;
		for (int j=i+1;j<=n;j++)
		{
			int x=now/a[j]+1;
			sum+=x,now=a[j]*x;
		}now=0;
		for (int j=i-1;j>=1;j--)
		{
			int x=now/a[j]+1;
			sum+=x,now=a[j]*x;
		}
		ckmin(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
}