#include<bits/stdc++.h>
using namespace std;

int n,a[100010],c[200010],cn,C[200010],Cn;
pair<int,int> b[100010];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),b[i]=make_pair(a[i],i);
	sort(b+1,b+1+n);
	c[1]=2*b[n].second-1,c[b[n].first+1]=2*b[n].second;
	for (int i=2; i<=b[n].first; i++) 
		c[i]=b[n-i+1].second*2-1;
	cn=b[n].first+1;
	for (int i=1; i<=b[n].first; i++) printf("%d %d\n",c[i],c[i+1]);
	Cn=cn;
	for (int i=1; i<=cn; i++) C[i]=c[i];
	for (int i=2; i<=b[n].first; i++)
	{
		int x=n-i+1;
		if (i+b[x].first>cn)
		{
			printf("%d %d\n",c[cn],b[x].second*2);
			c[++cn]=b[x].second*2;
		} else
		{
			printf("%d %d\n",c[i+b[x].first-1],b[x].second*2);
		}
	}
	for (int i=1; i<=n-b[n].first; i++)
	{
		if (b[i].first==1) printf("%d %d\n",b[i].second*2,b[i].second*2-1),printf("%d %d\n",b[i].second*2,b[n].second*2-1);
		else printf("%d %d\n",b[i].second*2,b[n].second*2-1),printf("%d %d\n",b[i].second*2-1,c[b[i].first-1]);
	}
	return 0;
}