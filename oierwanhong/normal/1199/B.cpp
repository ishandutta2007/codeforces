//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
/*
x^2=(x-h)^2+l^2
0=-2hx+h^2+l^2
2hx=h^2+l^2
*/
int main()
{
	double h,l;
	std::cin>>h>>l;
	printf("%.8lf",(h*h+l*l)/h/2.0-h);
	return 0;
}