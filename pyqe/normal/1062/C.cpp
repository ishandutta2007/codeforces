#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069],pwk,dv=1e9+7;

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
	long long t,rr,i,k,l,w,ln;
	string s;
	
	scanf("%lld%lld",&n,&t);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+(s[i-1]-'0');
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		ln=l-k+1;
		w=ps[l]-ps[k-1];
		printf("%lld\n",(pw(2,ln)+dv-pw(2,ln-w))%dv);
	}
}