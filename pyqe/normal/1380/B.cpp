#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,yk[26],fq[3],inf=1e18;
string ky="RPS";

int main()
{
	long long t,rr,i,e;
	pair<long long,long long> mxe;
	string s;
	
	for(i=0;i<3;i++)
	{
		yk[ky[i]-'A']=i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<3;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			fq[yk[s[i]-'A']]++;
		}
		mxe={-inf,-1};
		for(i=0;i<3;i++)
		{
			mxe=max(mxe,{fq[i],i});
		}
		e=mxe.sc;
		for(i=0;i<n;i++)
		{
			printf("%c",ky[(e+1)%3]);
		}
		printf("\n");
	}
}