#include <bits/stdc++.h>

using namespace std;

long long n,d,dg;
string ky[2]={"Ayush","Ashish"};

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		dg=0;
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			dg+=(k==d)+(l==d);
		}
		z=(n-2)*(dg>1);
		printf("%s\n",ky[z%2].c_str());
	}
}