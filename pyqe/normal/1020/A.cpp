#include <bits/stdc++.h>

using namespace std;

long long n,m,lb,rb;

int main()
{
	long long t,rr,y,x,y2,x2;
	
	scanf("%lld%lld%lld%lld%lld",&n,&m,&lb,&rb,&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
		printf("%lld\n",abs(y-y2)+abs(x-x2)+(max(min(x,x2)-rb,0ll)+max(lb-max(x,x2),0ll))*2*(y!=y2));
	}
}