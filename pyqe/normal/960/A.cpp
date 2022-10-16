#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],fq[3];

int main()
{
	long long i;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
		if(a[i]<a[i-1])
		{
			printf("NO\n");
			return 0;
		}
		fq[a[i]]++;
	}
	if(min({fq[0],fq[1],fq[2]})&&(fq[2]==fq[0]||fq[2]==fq[1]))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}