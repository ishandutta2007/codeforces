#include <bits/stdc++.h>

using namespace std;

long long n,mn[100069],a[100069],sz=0,z[100069];
stack<long long> sk;

int main()
{
	long long i;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		a[i]=s[i]-'a';
	}
	mn[n]=26;
	for(i=n-1;i>=0;i--)
	{
		mn[i]=min(mn[i+1],a[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(;!sk.empty()&&(i==n||sk.top()<=mn[i]);sk.pop())
		{
			z[sz]=sk.top();
			sz++;
		}
		if(i<n)
		{
			sk.push(a[i]);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%c",z[i]+'a');
	}
	printf("\n");
}