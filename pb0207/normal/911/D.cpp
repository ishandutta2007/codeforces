#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e3+1e3+7;

int n,a[N];

int ans,q;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans^=(a[i]>a[j]);
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ans^=((r-l+1)%4>=2);
		puts(ans?"odd":"even");
	}
}