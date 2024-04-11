#include <bits/stdc++.h>

using namespace std;

long long n,m,d,d2;

int main()
{
	long long w,w2,rm,rm2,z;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&d2);
	if(d2==n)
	{
		d2=((d2-1)/m+1)*m;
	}
	w=(d-1)/m+1;
	w2=(d2-1)/m+1;
	rm=(d-1)%m+1;
	rm2=(d2-1)%m+1;
	if(w==w2||(rm==1&&rm2==m))
	{
		z=1;
	}
	else if(rm==1||rm2==m||w+1==w2||rm-1==rm2)
	{
		z=2;
	}
	else
	{
		z=3;
	}
	printf("%lld\n",z);
}