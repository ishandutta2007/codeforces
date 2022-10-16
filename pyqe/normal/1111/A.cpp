#include <bits/stdc++.h>

using namespace std;

long long n[2];
bitset<26> yk;
bitset<100069> a[2];

int main()
{
	long long i,ii;
	string s;
	
	yk[0]=1;
	yk[4]=1;
	yk[8]=1;
	yk[14]=1;
	yk[20]=1;
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		n[ii]=s.length();
		for(i=1;i<=n[ii];i++)
		{
			a[ii][i]=yk[s[i-1]-'a'];
		}
	}
	if(n[0]!=n[1])
	{
		printf("No\n");
		return 0;
	}
	for(i=1;i<=n[0];i++)
	{
		if(a[0][i]^a[1][i])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}