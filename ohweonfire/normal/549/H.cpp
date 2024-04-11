#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	double l=0.0,r=1000000000.0;
	for(int _=1;_<=10000;_++)
	{
		double mid=(l+r)/2;
		double e=(a-mid)*(d-mid);
		double f=(a-mid)*(d+mid);
		double g=(a+mid)*(d-mid);
		double h=(a+mid)*(d+mid);
		double i=(b-mid)*(c-mid);
		double j=(b-mid)*(c+mid);
		double k=(b+mid)*(c-mid);
		double m=(b+mid)*(c+mid);
		double x1=min(e,min(f,min(g,h)));
		double x2=max(e,max(f,max(g,h)));
		double y1=min(i,min(j,min(k,m)));
		double y2=max(i,max(j,max(k,m)));
		if(max(x1,y1)<min(x2,y2)+0.00000000000000000000001)
			r=mid;
		else
			l=mid;
	}
	printf("%.10lf\n",l);
	return 0;
}