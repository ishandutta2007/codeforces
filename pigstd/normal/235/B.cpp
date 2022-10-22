#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
double x1[M],x2[M],ans[M],a[M];
// 
// 
int n;

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		x1[i]=(x1[i-1]+1)*a[i],
		ans[i]=ans[i-1]+(2*x1[i-1]+1)*a[i];
	printf("%.11lf",ans[n]);
	return 0;
}