#include<cstdio>
#include<iostream> 
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,m,a[N],f[N],g[N],w[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		a[l]++,a[r+1]--;
	}
	for(int i=1;i<=m;i++)
		a[i]+=a[i-1];
	
	memset(w,0x3f,sizeof(w));
	for(int i=1;i<=m;i++)
	{
		f[i]=upper_bound(w+1,w+m+1,a[i])-w;
		w[f[i]]=a[i];
	}
	
	reverse(a+1,a+m+1);
	
	memset(w,0x3f,sizeof(w));
	for(int i=1;i<=m;i++)
	{
		g[m-i+1]=upper_bound(w+1,w+m+1,a[i])-w;
		w[g[m-i+1]]=a[i];
	}
	
	int ans=0;
	for(int i=1;i<=m;i++)
		ans=max(ans,f[i]+g[i]-1);
	printf("%d",ans);
}