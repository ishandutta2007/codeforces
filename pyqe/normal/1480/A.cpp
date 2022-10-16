#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,u,k,e,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'a';
			e=i%2==0;
			u=!e*2-1;
			z=25*e;
			printf("%c",(char)(z+(k==z)*u)+'a');
		}
		printf("\n");
	}
}