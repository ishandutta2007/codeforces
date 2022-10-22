#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],last=-1,mn=0x7fffffff;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),mn=min(mn,a[i]);
	int ans=n+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==mn)
		{
			if(last==-1)
				last=i;
			else
				ans=min(ans,i-last),last=i;
		}
	}
	printf("%d",ans);
}