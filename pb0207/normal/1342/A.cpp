#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

long long T,a,b,x,y;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		if(b>a*2)
			b=a*2;
		if(x>y)
			swap(x,y);
		printf("%lld\n",(y-x)*a+b*x);
	}
	
}