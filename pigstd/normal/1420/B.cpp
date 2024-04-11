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

const int M=1e5+10;
int n,a[M];

signed main()
{
	WT
	{
		n=read();int ans=0;
		for (int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);int l=0;
		for (int i=0;i<=30;i++)
		{
			int x=l;
			while(l<=n&&a[l]<(1<<i))l++;
			l--;ans+=(l-x)*(l-x);
		}ans-=n;ans/=2;
		cout<<ans<<endl;
	}
	return 0;
}