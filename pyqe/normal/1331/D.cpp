#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long k;
	string s;
	
	cin>>s;
	n=s.length();
	k=s[n-1]-'0';
	printf("%lld\n",k%2);
}