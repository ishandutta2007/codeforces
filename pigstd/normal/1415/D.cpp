#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int n,a[M],sum[M],ans=1e18;

inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)sum[i]=a[i]^sum[i-1];
	if (n>100){puts("1");return 0;}
	for (int i=1;i<=n-2;i++)
	{
		int x=a[i]^a[i+1];
		if(x<a[i-1]||x>a[i+2])
		{
			puts("1");
			return 0;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=i;k<j;++k)
			{
				int x=sum[k]^sum[i-1];
				int y=sum[j]^sum[k];
				if(x>y)ans=min(ans,j-i-1);
			}
	if (ans==1e18)puts("-1");
	else cout<<ans;
	return 0;
}