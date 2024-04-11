#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fq[4],zs,sq[100069];
map<char,long long> yk;
string ky="URDL";

int main()
{
	long long t,rr,i,j,c,mn[2];
	string s;
	
	yk['U']=0;
	yk['R']=1;
	yk['D']=2;
	yk['L']=3;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<4;i++)
		{
			fq[i]=0;
		}
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			fq[yk[s[i-1]]]++;
		}
		for(i=0;i<2;i++)
		{
			mn[i]=min(fq[i],fq[i+2]);
		}
		if(!mn[0]&&!mn[1])
		{
			zs=0;
		}
		else if(!mn[0])
		{
			zs=2;
			sq[1]=1;
			sq[2]=3;
		}
		else if(!mn[1])
		{
			zs=2;
			sq[1]=0;
			sq[2]=2;
		}
		else
		{
			zs=mn[0]*2+mn[1]*2;
			for(c=1,i=0;i<4;i++)
			{
				for(j=0;j<mn[i%2];j++,c++)
				{
					sq[c]=i;
				}
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%c",ky[sq[i]]);
		}
		printf("\n");
	}
}