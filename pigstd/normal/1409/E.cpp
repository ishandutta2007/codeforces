#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int T,lm[M],rm[M],n,k,a[M],b[M],ans;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	T=read();
	while(T--)
	{
		n=read(),k=read();
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=1;i<=n;i++)b[i]=read();
		sort(a+1,a+1+n);
		int l=1,r=1;
		while(l<=n)
		{
			while(a[r]-a[l]<=k&&r<=n)r++;
			if (a[r]-a[l]>k||r==n+1)r--;
			lm[l]=r-l+1;l++;
		}
		for (int j=n;j>=1;j--)
			rm[j]=max(rm[j+1],lm[j]);
		for (int i=1;i<=n;i++)
			ans=max(ans,lm[i]+rm[i+lm[i]]);
		cout<<ans<<endl;ans=0;
		for (int i=1;i<=n;i++)lm[i]=rm[i]=a[i]=b[i]=0;
	}
	return 0;
}