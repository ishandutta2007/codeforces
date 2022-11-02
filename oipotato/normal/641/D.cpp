#include <cstdio>
#include <cmath>
using namespace std;
double p[100010][2],maxp[100010],minp[100010],s1,s2;
int n;
void work(double sum,double ab,double &a,double &b)
{
	a=(sqrt(abs(sum*sum-4*ab))+sum)/2;
	b=sum-a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&maxp[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&minp[i]);
	}
	s1=s2=0;
	for(int i=1;i<=n;i++)
	{
		work(maxp[i]+minp[i]+s2-s1,maxp[i]-s1*(maxp[i]+minp[i]),p[i][0],p[i][1]);
		p[i][1]-=s2-s1;
		s1+=p[i][0];
		s2+=p[i][1];
	}
	for(int i=1;i<n;i++)
	{
		printf("%.10lf ",p[i][0]);
	}
	printf("%.10lf\n",p[n][0]);
	for(int i=1;i<n;i++)
	{
		printf("%.10lf ",p[i][1]);
	}
	printf("%.10lf\n",p[n][1]);
	return 0;
}