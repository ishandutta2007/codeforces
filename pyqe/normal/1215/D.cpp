#include <bits/stdc++.h>

using namespace std;

long long n,z[2],c[2],n2,cc;

int main()
{
	long long i,it;
	string s;
	
	scanf("%lld",&n);
	n2=n/2;
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]=='?')
		{
			c[i/n2]++;
		}
		else
		{
			z[i/n2]+=s[i]-'0';
		}
	}
	//z[0]=222355;
	//z[1]=226982;
	//c[0]=50582;
	//c[1]=49418;
	cc=(c[0]+c[1])/2;
	if(z[0]+(c[0]+1)/2*9-z[1]<=(cc-c[0]/2)*9&&z[1]+(c[1]+1)/2*9-z[0]<=(cc-c[1]/2)*9)
	{
		printf("Bicarp\n");
	}
	else
	{
		printf("Monocarp\n");
	}
}