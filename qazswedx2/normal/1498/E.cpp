#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],c[100005],ans=-1,u,v;
bool cmp(const int x,const int y)
{
	return a[x]<a[y];
}
inline void upd(int l,int r)
{
	if(l!=r&&a[c[r]]-a[c[l]]>ans)
	{
		ans=a[c[r]]-a[c[l]];
		u=c[r],v=c[l];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),c[i]=i;
	sort(c+1,c+n+1,cmp);
	int sum=0,las=1;
	for(int i=1;i<n;i++)
	{
		sum+=a[c[i]];
		if(sum==1ll*i*(i-1)/2)
		{
			upd(las,i);
			las=i+1;
		}
	}
	upd(las,n);
	printf("! %d %d\n",u,v);
	return 0;
}