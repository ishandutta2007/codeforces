#include <cstdio>
#include <algorithm>
using namespace std;
struct datas
{
	int l,r;
}data[200010];
int n,l1,l2;
bool cmp(datas a,datas b){return a.l<b.l;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&data[i].l,&data[i].r);
	}
	sort(data+1,data+n+1,cmp);
	l1=l2=-1;
	for(int i=1;i<=n;i++)
	{
		if(l1<l2)
			swap(l1,l2);
		if(data[i].l>l1)
			l1=data[i].r;
		else if(data[i].l>l2)
			l2=data[i].r;
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}