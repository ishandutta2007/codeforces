#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[500005],g[500005],b[500005],c[500005],tb[500005];
ll sum,f[500005];
bool cmp(const int x,const int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),c[i]=i;
	sort(c+1,c+n+1,cmp);
	sort(a+1,a+n+1);
	f[0]=0;
	f[1]=-1e9;
	f[2]=-1e9;
	ll nw=0;
	int id=0,cnt=1;
	for(int i=3;i<n;i++)
	{
		if(f[i-3]>nw) id=i-3;
		nw=max(nw,f[i-3]);
		f[i]=nw+a[i+1]-a[i];
		g[i]=id;
	}
	if(f[n-3]>nw) id=n-3;
	nw=max(nw,f[n-3]);
	///(int i=1;i<=n;i++)
	//	printf("%d ",f[i]);
	while(id)
	{
		b[id+1]++;
		cnt++;
		id=g[id];
	}
	for(int i=1;i<=n;i++)
		b[i]+=b[i-1];
	for(int i=1;i<=n;i++)
		tb[c[i]]=b[i];
	printf("%I64d %d\n",a[n]-a[1]-nw,cnt);
	for(int i=1;i<=n;i++)
		printf("%d ",tb[i]+1);
	return 0;
}