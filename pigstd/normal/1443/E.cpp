#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int M=2e5+10;
int n,q,a[M],fac[20],vis[M];

signed main()
{
	n=read(),q=read();
	fac[0]=1;for (int i=1;i<=15;i++)fac[i]=fac[i-1]*i;
	if (n<=15)
	{
		for (int i=1;i<=n;i++)
			a[i]=i;int x=0; 
		while(q--)
		{
			int opt=read();
			if (opt==1)
			{
				int l=read(),r=read();
				int sum=0;
				for (int i=l;i<=r;i++)
					sum+=a[i];
				cout<<sum<<endl;
			}
			else
			{
				x+=read();int now=0;
				for (int i=1;i<=n;i++)vis[i]=0;
				for (int i=1;i<=n;i++)
				{
					int cnt=0;a[i]=0;
					for (int j=1;j<=n;j++)
					{
						if (a[i])break;
						if (!vis[j])cnt++;
						if (cnt*fac[n-i]+now>x)
							now+=(cnt-1)*fac[n-i],vis[j]=1,a[i]=j;
					}
				}
			}
		}
		return 0;
	}
	else
	{
		for (int i=1;i<=n;i++)
			a[i]=i;int x=0; 
		while(q--)
		{
			int opt=read();
			if (opt==1)
			{
				int l=read(),r=read();
				int sum=0;
				if (l<=n-15&&r<=n-15)
					sum=(l+r)*(r-l+1)/2,l=n-14;
				else if (l<=n-15&&r>n-15)
					sum=(l+n-15)*(n-14-l)/2,l=n-14;
				for (int i=l;i<=r;i++)
					sum+=a[i];
				cout<<sum<<endl;
			}
			else
			{
				x+=read();int now=0;
				for (int i=n-15;i<=n;i++)vis[i]=0;
				for (int i=n-15;i<=n;i++)
				{
					int cnt=0;a[i]=0;
					for (int j=n-15;j<=n;j++)
					{
						if (a[i])break;
						if (!vis[j])cnt++;
						if (cnt*fac[n-i]+now>x)
							now+=(cnt-1)*fac[n-i],vis[j]=1,a[i]=j;
					}
				}
			}
		}
	}
	return 0;
}