#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long st,fn,st2,t1,t2,t3,z,z2;
	
	scanf("%lld%lld%lld%lld%lld%lld",&st,&fn,&st2,&t1,&t2,&t3);
	z=abs(st-fn)*t1;
	z2=(abs(st2-st)+abs(st-fn))*t2+t3*3;
	if(z2<=z)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}