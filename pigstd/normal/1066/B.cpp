#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1005;
const int inf=1e18;
int f[M],n,r,a[M];

signed main()
{
	n=read(),r=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	memset(f,0x3f,sizeof(f));f[0]=0;
	for (int i=1;i<=n;i++)
		if (a[i]==1)
		{
			if (i<=r)f[i]=1;
			else f[i]=inf;
			for (int j=max(1ll,i-2*r+1);j<i;j++)
				f[i]=min(f[i],f[j]+1);
		}int ans=1e18;
	for (int i=max(1ll,n-r+1);i<=n;i++)
		ans=min(ans,f[i]);
	if (ans==1e18)puts("-1");
	else cout<<ans<<endl;
	return 0;
}