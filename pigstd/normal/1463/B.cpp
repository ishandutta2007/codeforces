#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define int long long
#define pb push_back
#define YES puts("YES")
#define NO puts("NO")
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=55;
int n,a[M];

signed main()
{
	WT
	{
		n=read();int sum=0,sum1=0,sum2=0;
		for (int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
		for (int i=1;i<=n;i++)
		{
			if (i&1)sum1+=a[i]-1;
			else sum2+=a[i]-1;
		}
		if (sum1>sum2)
		{
			for (int i=1;i<=n;i++)
			{
				if (i&1)cout<<a[i]<<' ';
				else cout<<1<<' ';
			}
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				if (i&1)cout<<1<<' ';
				else cout<<a[i]<<" ";
			}
		}puts("");
	}
	return 0;
}