#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a[4],ln,i,z=0;
	string s;
	
	for(i=0;i<4;i++)
	{
		scanf("%lld",a+i);
	}
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		z+=a[s[i]-49];
	}
	printf("%lld\n",z);
}