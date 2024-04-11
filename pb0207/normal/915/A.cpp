#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,k,a[N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(k%a[i]==0)
			ans=max(ans,a[i]);
	printf("%d",k/ans);
}