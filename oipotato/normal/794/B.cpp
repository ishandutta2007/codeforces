#include<bits/stdc++.h>
using namespace std;
int n,h;
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=1;i<n-1;i++)printf("%lf ",sqrt(1.0*i/n)*h);
	printf("%lf",sqrt(1.0*(n-1)/n)*h);
	return 0;
}