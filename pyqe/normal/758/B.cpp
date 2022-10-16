#include <bits/stdc++.h>

using namespace std;

long long n,yk[269],fq[4],a[4];
string ky="RBYG!";

int main()
{
	long long i,k;
	string s;
	
	for(i=0;i<5;i++)
	{
		yk[ky[i]]=i;
	}
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		k=yk[s[i]];
		if(k<4)
		{
			a[k]=i%4;
		}
		else
		{
			fq[i%4]++;
		}
	}
	for(i=0;i<4;i++)
	{
		printf("%lld%c",fq[a[i]]," \n"[i==3]);
	}
}