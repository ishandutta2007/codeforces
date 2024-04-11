#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=5005;
int a[maxn],b[maxn],ord[maxn],n,minn;
bool cmp(int x,int y)
{
	if(a[x]!=a[y])
		return a[x]<a[y];
	return b[x]<b[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",a+i,b+i);
		ord[i]=i;
	}
	sort(ord+1,ord+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(minn<=b[ord[i]])
			minn=b[ord[i]];
		else
			minn=a[ord[i]];
	printf("%d\n",minn);
	return 0;
}