#include <bits/stdc++.h>
using namespace std;
double f[100005];
int main()
{
	int n,k,ub;
	scanf("%d%d",&n,&k);
	ub=min(n,80000000/n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=ub;j++)
			f[j]=(k-1)*1.0/k*f[j]+1.0/k/(j+1)*(j*f[j]+j*0.5*(j+1)+f[j+1]+j);
	printf("%.12lf\n",f[1]*k);
}