#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int n,d,sum[M],ans;
struct node
{
	int a,b;
}a[M];

bool cmp(node a,node b)
{
	return a.a<b.a;
}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read(),d=read();
	for (int i=1;i<=n;i++)a[i].a=read(),a[i].b=read();
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i].b;
	for (int i=1,l=1;i<=n;i++)
	{
		while(l<=i&&a[i].a-a[l].a>=d)l++;
		ans=max(ans,sum[i]-sum[l-1]);
	}
	cout<<ans;
	return 0;
}