#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1e3;

int n,m,a[N];
struct qwq
{
	int x,y;
}b[N];
bool cmp(qwq a,qwq b)
{
	return a.x<b.x;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d%d",&b[i].x,&b[i].y);
	sort(b+1,b+1+m,cmp);
	for (int i=1;i<=m;i++) b[i].y+=b[i-1].y;
	for (int i=1;i<=n;i++)
	{
		int l=1,r=m;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (b[mid].x<=a[i]) l=mid+1;
						   else r=mid-1;
		}
		printf("%d ",b[r].y);
	}

	return 0;
}