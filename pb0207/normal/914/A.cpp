#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],ans=-0x7fffffff;

bool chk(int x)
{
	return (int)((int)sqrt((double)x+0.5)*(int)sqrt((double)x+0.5))!=x;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<0||chk(a[i]))
			ans=max(ans,a[i]);
	}
	printf("%d",ans);
}