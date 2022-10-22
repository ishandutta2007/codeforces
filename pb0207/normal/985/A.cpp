#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n/2+1);
	int tot=0,ans=0x7fffffff;
	for(int i=1;i<=n;i+=2)
		tot+=abs(i-a[i/2+1]);
	ans=min(ans,tot);
	tot=0;
	for(int i=2;i<=n;i+=2)
		tot+=abs(i-a[i/2]);
	ans=min(ans,tot);
	printf("%d",ans);
}