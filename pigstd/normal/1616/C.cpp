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

const int M=100;
int a[M];

signed main()
{
	WT
	{
		int n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		int ans=n-1;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
			{
				int cnt=0;int d=(a[j]-a[i]),c=j-i;
				for (int k=1;k<=n;k++)
					if (c*a[k]!=k*d+a[i]*c-i*d)cnt++;
				ckmin(ans,cnt);
			}
		cout<<ans<<'\n';
	}
	return 0;
}