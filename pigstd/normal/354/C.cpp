#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e6+10;
int n,k,sum[M],a[M],minn=1e18,ans=0;

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)a[i]=read(),sum[a[i]]++,minn=min(minn,a[i]);
	if (minn<=k+1)return printf("%lld\n",minn),0;
	for (int i=1;i<=1e6;i++)sum[i]+=sum[i-1];
	for (int i=1;i<=1e6;i++)
	{
		int Sum=0;
		for (int j=i;j<=1e6;j+=i)
			Sum+=sum[min(1000000ll,j+k)]-sum[j-1];
		if (Sum>=n)ans=i;
	}cout<<ans<<endl;
	return 0;
}