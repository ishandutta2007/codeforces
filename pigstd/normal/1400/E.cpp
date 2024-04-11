#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=5010;
int a[M],n;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int f(int l,int r)
{
	if (l>r)return 0;
	if (l==r)return min(a[l],1ll);
	int maxn=1e9,p=0;
	for (int i=l;i<=r;i++)
		if (maxn>a[i])
			maxn=a[i],p=i;
	for (int i=l;i<=r;i++)a[i]-=maxn;
	return min(r-l+1,maxn+f(l,p-1)+f(p+1,r));
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	int ans=f(1,n);
	cout<<ans<<endl;
	return 0;
}