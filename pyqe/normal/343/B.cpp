#include <bits/stdc++.h>

using namespace std;

long long n,nn=0;
bitset<100069> sk;

int main()
{
	long long i,k;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		k=s[i]=='+';
		if(!nn||k!=sk[nn])
		{
			nn++;
			sk[nn]=k;
		}
		else
		{
			nn--;
		}
	}
	if(!nn)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}