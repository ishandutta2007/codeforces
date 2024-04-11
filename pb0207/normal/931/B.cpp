#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a,b;

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	a+=n-1,b+=n-1;
	int ans=0;
	while(a!=b)
	{
		ans++;
		a>>=1;
		b>>=1;
	}
	if(a!=1)
		printf("%d",ans);
	else
		puts("Final!");
}