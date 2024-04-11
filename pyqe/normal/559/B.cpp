#include <bits/stdc++.h>

using namespace std;

long long n;
string s[2];

void srt(long long ix,long long lh,long long rh)
{
	if((rh-lh+1)%2==0)
	{
		long long i,md=(lh+rh)/2;
		
		srt(ix,lh,md);
		srt(ix,md+1,rh);
		if(s[ix].substr(lh,rh-md)>s[ix].substr(md+1,rh-md))
		{
			for(i=lh;i<=md;i++)
			{
				swap(s[ix][i],s[ix][i+rh-md]);
			}
		}
	}
}

int main()
{
	long long ii;
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s[ii];
		n=s[ii].length();
		srt(ii,0,n-1);
	}
	if(s[0]==s[1])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}