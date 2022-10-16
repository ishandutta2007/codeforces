#include <bits/stdc++.h>

using namespace std;

long long n,m,n2,m2,d,dn,dm;

int main()
{
	long long t,rr,i,cn,cm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&m,&n2,&m2,&d,&dm,&dn);
		for(i=0;i<=d;i++)
		{
			cn=n+i*dn;
			cm=m+(d-i)*dm;
			if((n2-1)/cm+1<=(cn-1)/m2+1)
			{
				break;
			}
		}
		if(i<=d)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}