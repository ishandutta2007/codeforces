#include <bits/stdc++.h>

using namespace std;

long long n,m;
string a="<3",s;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		a+=s+"<3";
	}
	cin>>s;
	n=a.length();
	m=s.length();
	for(j=0,i=0;i<n;i++,j++)
	{
		for(;j<m&&s[j]!=a[i];j++);
		if(j==m)
		{
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
}