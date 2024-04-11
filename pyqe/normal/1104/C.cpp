#include <bits/stdc++.h>

using namespace std;

bool al[2];

int main()
{
	long long ln,i,k;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		k=s[i]-48;
		if(!al[k])
		{
			printf("%lld %lld\n",3-(1-k)*2,3-k*2);
		}
		else
		{
			printf("3 3\n");
		}
		al[k]=!al[k];
	}
}