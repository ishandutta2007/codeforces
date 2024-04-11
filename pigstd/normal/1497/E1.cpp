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

const int M=2e5+10;
const int N=1e7+10;
int n,k,a[M],b[M],cnt,prime[M*10];
bool t1[N],f[N];
//
signed main()
{
	for (int i=2;i<=1e7;i++)
		if (!f[i])
		{
			prime[++cnt]=i;
			for (int j=i*i;j<=1e7;j+=i)
				f[j]=1;
		}
	WT
	{
		n=read(),k=read();int ans=0,l=1,r=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();b[i]=1;int pp=a[i];
			for (int j=1;j<=cnt&&prime[j]*prime[j]<=a[i];j++)
			{
				while(pp%(prime[j]*prime[j])==0)a[i]/=prime[j]*prime[j],pp/=prime[j]*prime[j];
				if (pp%prime[j]==0)b[i]*=prime[j],pp/=prime[j];
			}
			if (pp)b[i]*=pp;
		}
		for (r=1;r<=n;r++)
		{
			if (t1[b[r]])
			{
				for (int i=l;i<r;i++)t1[a[i]]=0;
				l=r,ans++;
			}
			t1[a[r]]=1;
		}
		ans++;
		for (int i=l;i<=n;i++)t1[a[i]]=0;
		cout<<ans<<endl;
	}
	return 0;
}