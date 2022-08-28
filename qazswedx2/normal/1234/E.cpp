#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[1000005];
ll c[1000005];
void modify(int l,int r,int v)
{
	if(l>r) return;
	c[l]+=v;
	c[r+1]-=v;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<m;i++)
	{
		int l=a[i],r=a[i+1];
		if(l>r) swap(l,r);
		if(l==r) continue;
		modify(1,l-1,r-l);
		modify(l,l,r-1);
		modify(l+1,r-1,r-l-1);
		modify(r,r,l);
		modify(r+1,n,r-l);
	} 
	for(int i=1;i<=n;i++)
		c[i]+=c[i-1];
	for(int i=1;i<=n;i++)
		printf("%I64d ",c[i]);
	return 0;
}