#include <bits/stdc++.h>

using namespace std;

long long a[2][1000069];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long i,ii,ln;
	string s;
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		ln=s.length();
		for(i=0;i<ln;i++)
		{
			a[ii][1000000-i]=s[ln-1-i]-'0';
		}
	}
	for(i=1;i<=1000000;i++)
	{
		if(a[0][i]<a[1][i])
		{
			printf("<\n");
			return 0;
		}
		else if(a[0][i]>a[1][i])
		{
			printf(">\n");
			return 0;
		}
	}
	printf("=\n");
}