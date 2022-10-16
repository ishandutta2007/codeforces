#include <bits/stdc++.h>

using namespace std;

long long n,fq[3];

int main()
{
	long long t,rr,i;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<3;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			fq[s[i]-'A']++;
		}
		if(fq[0]+fq[2]==fq[1])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}