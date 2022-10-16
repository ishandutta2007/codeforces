#include <bits/stdc++.h>

using namespace std;

long long n,d[2],fq[3];

int main()
{
	long long i,k;
	string s;
	
	cin>>s;
	n=s.length();
	d[0]=(n-2)/2;
	d[1]=(n-1)/2;
	for(i=0;i<n;i++)
	{
		k=(s[i]=='1')+2*(s[i]=='?');
		fq[k]++;
	}
	if(fq[0]+fq[2]-d[0]>=2)
	{
		printf("00\n");
	}
	if(k&&fq[0]-d[0]<=1&&fq[1]+(k==2)-d[1]<=1)
	{
		printf("01\n");
	}
	if(k!=1&&fq[0]+(k==2)-d[0]<=1&&fq[1]-d[1]<=1)
	{
		printf("10\n");
	}
	if(fq[1]+fq[2]-d[1]>=2)
	{
		printf("11\n");
	}
}