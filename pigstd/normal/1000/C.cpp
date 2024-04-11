#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2*1e5+10;
int n,ans[M],sum,c[M*2];

struct node
{
	int a,p;
}a[M*2],b[M*2];

bool cmp(node a,node b)
{
	return a.a<b.a;
}

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int l,r;
		cin>>l>>r;
		a[i*2-1].a=l,a[i*2-1].p=1;
		a[i*2].a=r+1,a[i*2].p=-1;
	}
	sort(a+1,a+1+n*2,cmp);
	b[1]=a[1],sum=1;
	for (int i=2;i<=n*2;i++)
	{
		if (a[i].a==b[sum].a)
			b[sum].p+=a[i].p;
		else
			b[++sum].a=a[i].a,b[sum].p=a[i].p;
	}
	for (int i=1;i<=sum;i++)
		c[i]=c[i-1]+b[i].p;
	for (int i=2;i<=sum;i++)
		ans[c[i-1]]+=(b[i].a-b[i-1].a);
	for (int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}