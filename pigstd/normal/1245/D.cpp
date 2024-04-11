#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=3e6+1e5;
int x[M],y[M],n,c[M],k[M],cnt,ans;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct edge
{
	int u,v,w;
}a[M];

bool cmp(edge a,edge b)
{
	return a.w<b.w;
} 

int f[M];
int find(int k)
{
	return f[k]==k?k:f[k]=find(f[k]);
}

signed main()
{
	n=read();f[n+1]=n+1;
	for (int i=1;i<=n;i++)
		x[i]=read(),y[i]=read(),f[i]=i;
	for (int i=1;i<=n;i++)c[i]=read();
	for (int i=1;i<=n;i++)k[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			a[++cnt].u=i,a[cnt].v=j,a[cnt].w=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
	for (int i=1;i<=n;i++)
		a[++cnt].u=i,a[cnt].v=n+1,a[cnt].w=c[i];
	sort(a+1,a+1+cnt,cmp);int sum=0;
	for (int i=1;i<=cnt;i++)
	{
		int u=a[i].u,v=a[i].v;
		if (find(u)==find(v))continue;
		sum++,f[find(u)]=find(v),ans+=a[i].w,a[sum]=a[i];
		if (sum==n)break;
	}
	cout<<ans<<endl;int cnt1=0;
	for (int i=1;i<=n;i++)
		if (a[i].v==n+1)cnt1++;
	cout<<cnt1<<endl;
	for (int i=1;i<=n;i++)
		if (a[i].v==n+1)cout<<a[i].u<<' '; 
	cout<<endl<<n-cnt1<<endl;
	for (int i=1;i<=n;i++)
		if (a[i].v!=n+1)cout<<a[i].u<<' '<<a[i].v<<endl;
	return 0;
}