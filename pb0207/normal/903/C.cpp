#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=5e3+1e2+7;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int now=0,mx=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1])
		{
			mx=max(mx,now);
			now=1;
		}
		else
			now++;
	mx=max(mx,now);
	cout<<mx;
}