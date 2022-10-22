#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int c[M],n,q,ans,a[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		c[l]++,c[r+1]--;
	}
	for (int i=1;i<=n;i++)c[i]+=c[i-1];
	sort(c+1,c+1+n);sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)ans+=c[i]*a[i];
	cout<<ans;
	return 0;
}