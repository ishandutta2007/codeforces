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

const int M=3e5+10;
int n,q,a[M],b[M];

signed main()
{
	WT
	{
		n=read(),q=read();int ans=0;
		for (int i=1;i<=n;i++)
			a[i]=read(),b[i]=a[i]-a[i-1],ans+=max(0ll,b[i]);
		b[n+1]=-a[n];
		cout<<ans<<endl;
		while(q--)
		{
			int l=read(),r=read();
			ans-=max(0ll,b[l]),ans-=max(0ll,b[l+1]),
			ans-=max(0ll,b[r]),ans-=max(0ll,b[r+1]);
			if (l+1==r)ans+=max(0ll,b[r]);
			swap(a[l],a[r]);
			b[l]=a[l]-a[l-1],b[l+1]=a[l+1]-a[l],b[r]=a[r]-a[r-1],b[r+1]=a[r+1]-a[r];
			ans+=max(0ll,b[l]),ans+=max(0ll,b[l+1]),
			ans+=max(0ll,b[r]),ans+=max(0ll,b[r+1]);
			if (l+1==r)ans-=max(0ll,b[r]);
			cout<<ans<<endl;
		}
		for (int i=1;i<=n+1;i++)a[i]=b[i]=0;
	}
	return 0;
}
/*
1
2 2
1 2
1 2
1 2
*/