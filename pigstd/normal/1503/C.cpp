#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int ans,maxn,n;

struct node
{
	int a,b;
}a[M];

bool cmp(node a,node b){return a.a<b.a;}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i].a=read(),a[i].b=read(),ans+=a[i].b;
	sort(a+1,a+1+n,cmp);
	maxn=a[1].a+a[1].b;
	for (int i=2;i<=n;i++)
		ans+=max(0ll,a[i].a-maxn),
		maxn=max(maxn,a[i].a+a[i].b);
	cout<<ans<<endl;
	return 0;
}