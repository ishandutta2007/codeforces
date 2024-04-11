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

const int M=2e5+10;
int n,m,f[M],g[M],ans;
struct node
{
	int a,b,w;
}a[M];
bool cmp(node a,node b){return a.w>b.w;}

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)f[i]=i;
	for (int i=1;i<=m;i++)
		a[i].a=read(),a[i].b=read(),a[i].w=read();
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m;i++)
	{
		int fa=find(a[i].a),fb=find(a[i].b);
		if (fa==fb)
		{
			if (g[fa]==0)
				g[fa]=1,ans+=a[i].w,f[fb]=fa;
		}
		else
		{
			if (g[fa]+g[fb]<2)
				f[fb]=fa,g[fa]+=g[fb],ans+=a[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}