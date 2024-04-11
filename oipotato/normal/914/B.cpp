#include<cstdio>
#include<iostream>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define y0 fucksub
#define y1 fuckjtjl
int n,x,a[100010],num[100010];
int main()
{
	scanf("%d",&n);
	x=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		num[x]++;
	}
	for(int i=1;i<=100000;i++)
	{
		if(num[i]%2)
		{
			puts("Conan");
			return 0;
		}
	}
	puts("Agasa");
	return 0;
}