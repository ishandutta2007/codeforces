#include <bits/stdc++.h>

using namespace std;

long long n[2],fq[2];

int main()
{
	long long i,ii;
	string s;
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		n[ii]=s.length();
		for(i=0;i<n[ii];i++)
		{
			fq[ii]+=s[i]-'0';
		}
	}
	if(n[0]==n[1]&&((n[0]>1&&fq[0]&&fq[1])||fq[0]==fq[1]))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}