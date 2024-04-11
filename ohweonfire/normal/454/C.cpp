#include <cstdio>
using namespace std;
double sum=0.0,ans=0.0;
double pow(double x,int m)
{
	double res=1.0;
	while(m)
	{
		if(m&1)res=res*x;
		x*=x;
		m>>=1;
	}
	return res;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		ans+=(pow(1.0*i/n,m)-pow(1.0*(i-1)/n,m))*i;
	printf("%.6lf\n",ans);
	return 0;
}