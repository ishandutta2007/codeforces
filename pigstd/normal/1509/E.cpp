#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

const int inf=1e18;
const int M=1e5+10;
int n,k,f[M];

signed main()
{
	WT
	{
		n=read(),k=read()-1;int la=0;
		if (n-1<=log2(k)){puts("-1");continue;}
		for (int i=0;i<=min(62ll,n-1);i++)
			f[n-i-1]=(1ll<<i)&k;int l=inf;
		for (int i=1;i<=n;i++)
		{
			if (f[i])l=min(l,i);
			else if (f[i-1])
			{
				for (int j=i;j>=l;j--)
					cout<<j<<' ';
				l=inf;
			}
			else cout<<i<<' ';
		}
		puts("");
		for (int i=0;i<=n;i++)f[i]=0;
	}
	return 0;
}