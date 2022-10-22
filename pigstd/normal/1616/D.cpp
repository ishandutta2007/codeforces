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

const int M=5e4+10;
int n,a[M],x;

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		x=read();
		for (int i=1;i<=n;i++)a[i]-=x;
		int ans=n,now=0,la=1;
		for (int i=1;i<=n;i++)
		{
			if (now+a[i]<0&&la!=i)ans--,now=0,la=i+1;
			else now=min(0ll,now)+a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}