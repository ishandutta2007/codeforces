#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	long long hf=(sum/2)+(sum%2!=0);
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
		if(ans>=hf)
		{
			printf("%d",i);
			return 0;
		}
	}
}