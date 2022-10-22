#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int n,a[M],t[M],p[M],ans;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=n;i>=1;i--)
	{
		p[i]=p[i+1];
		if (t[a[i]]==0)p[i]++;
		t[a[i]]=i;
	}
	for (int i=1;i<=1e5;i++)
		if (t[i]!=0)ans+=p[t[i]+1];
	cout<<ans;
	return 0;
}