#include <cstdio>
#include <algorithm>
using namespace std;
int a[200010],ans[200010],n;
struct datas
{
	int id,num;
	friend bool operator <(datas x,datas y)
	{
		return x.num<y.num;
	}
}data[200010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&data[i].num);
		data[i].id=i;
	}
	sort(data+1,data+n+1);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		ans[data[i].id]=a[n-i+1];
	for(int i=1;i<n;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}