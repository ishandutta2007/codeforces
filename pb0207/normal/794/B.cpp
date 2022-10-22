#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

const int N=1e3+1e2+7;

double ans[N],x;

int n,h;

int main()
{
	scanf("%d%d",&n,&h);
	x=(double)h/(double)n/(double)2;
	for(int i=1;i<=n-1;i++)
		ans[i]=sqrt(2*x*(double)h*(double)i);
	for(int i=1;i<=n-1;i++)
		printf("%.10lf\n",ans[i]);
}