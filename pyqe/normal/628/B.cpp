#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,w=0,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'0';
		w=(w*10+k)%100;
		z+=(i-1)*(w%4==0)+(k%4==0);
	}
	printf("%lld\n",z);
}