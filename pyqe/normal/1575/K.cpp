#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long dv=1e9+7;
long long n,m,d,n2,m2,pwk;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long y,x,y2,x2;
	
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&d,&n2,&m2,&y,&x,&y2,&x2);
	printf("%lld\n",pw(d,n*m-n2*m2*(mp(y,x)!=mp(y2,x2))));
}