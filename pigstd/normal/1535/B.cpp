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

const int M=2e3+10;
int n,a[M],b[M],cnt;

signed main()
{
	WT
	{
		n=read(),cnt=0;int ans=0;
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=1;i<=n;i++)
			if (a[i]%2==0)b[++cnt]=a[i];
		for (int i=1;i<=n;i++)
			if (a[i]&1)b[++cnt]=a[i];
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (__gcd(b[i],2*b[j])!=1)ans++;
		cout<<ans<<endl;
	}
	return 0;
}