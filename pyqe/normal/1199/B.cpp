#include <bits/stdc++.h>

using namespace std;

long long h,l;
double z;

int main()
{
	scanf("%lld%lld",&h,&l);
	z=(double)(h*h+l*l)/h/2-h;
	printf("%.13lf\n",z);
}