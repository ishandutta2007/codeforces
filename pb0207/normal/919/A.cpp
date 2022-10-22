#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

double m,mn=1e15;

int main()
{
	scanf("%d%lf",&n,&m);
	for(int i=1;i<=n;i++)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		mn=min(mn,a/b);
	}
	printf("%.8lf",mn*m);
}