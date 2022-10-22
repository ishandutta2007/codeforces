#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n*2;i+=2)
	{
		int pos;
		for(int j=i+1;j<=n*2;j++)
			if(a[j]==a[i])
				pos=j;
		for(int j=pos;j>i+1;j--)
			swap(a[j],a[j-1]),ans++;
	}
	printf("%d",ans);
}