#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
int T,n,f[M],a[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	T=read();
	while(T--)
	{
		n=read();int ans=0;
		for (int i=1;i<=n;i++)
			a[i]=read();
		for (int i=n;i>=1;i--)
			f[i]=f[(i+a[i])>n?0:(i+a[i])]+a[i],ans=max(ans,f[i]);
		for (int i=1;i<=n;i++)f[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}