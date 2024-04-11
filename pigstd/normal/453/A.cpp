#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int n,m;
double f[M],ans;

double poww(double a,int b)
{
	double res=1;
	while(b)
	{
		if (b&1)res*=a;
		a*=a;b>>=1;
	}return res;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		f[i]=poww(i*1.0/n,m);
	for (int i=1;i<=n;i++)
		ans+=(f[i]-f[i-1])*i;
	printf("%.12lf",ans);
	return 0;
}