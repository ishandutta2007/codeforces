#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<2> fq;

int main()
{
	long long t,rr,i,j,ln;
	string s;
	bool od;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		fq.reset();
		od=0;
		for(i=0;i<n;i++)
		{
			cin>>s;
			ln=s.length();
			if(ln%2==1)
			{
				od=1;
			}
			for(j=0;j<ln;j++)
			{
				fq[s[j]-'0']=!fq[s[j]-'0'];
			}
		}
		if(fq[0]&&fq[1]&&!od)
		{
			printf("%lld\n",n-1);
		}
		else
		{
			printf("%lld\n",n);
		}
	}
}