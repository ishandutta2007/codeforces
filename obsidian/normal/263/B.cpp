#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=60;
int a[V];
int n,K;
int main()
{
	while(~scanf("%d%D",&n,&K))
	{
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		a[n]=1000000001;
		if(K>n)puts("-1");
		else printf("%d %d\n",a[n-K],a[n-K]);
	}
}