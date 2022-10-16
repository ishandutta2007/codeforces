#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ln,fq[2][300069];

int main()
{
	long long i,j,ii,u,sm[2],e,z=0;
	pair<long long,long long> mxe;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		ln=s.length();
		for(ii=0;ii<2;ii++)
		{
			sm[ii]=0;
		}
		for(j=0;j<ln;j++)
		{
			u=(s[j]=='(')*2-1;
			sm[1]+=u;
			sm[0]+=sm[1]<0;
			sm[1]=max(sm[1],0ll);
		}
		if(!sm[0]||!sm[1])
		{
			mxe=max(mp(sm[0],0),{sm[1],1});
			e=mxe.sc;
			fq[e][sm[e]]++;
			fq[!e][sm[e]]+=(!sm[0]&&!sm[1]);
			z+=fq[!e][sm[e]]+(fq[e][sm[e]]-1)*(!sm[0]&&!sm[1]);
		}
	}
	printf("%lld\n",z);
}