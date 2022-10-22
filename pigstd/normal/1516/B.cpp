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

const int M=2020;
int a[M],sum[M],n;

signed main()
{
	WT
	{
		n=read();int f=0;
		for (int i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]^a[i];
		if (sum[n]==0)f=1;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (sum[i]==(sum[j]^sum[i])&&sum[i]==(sum[n]^sum[j]))
					f=1;
		if (f)YES
		else NO
	}
	return 0;
}