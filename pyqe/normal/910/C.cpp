#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,bool> fq[10];

int main()
{
	long long i,j,ln,k,ml,z=0;
	string s;
	bool bad=0,g;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		ln=s.length();
		ml=1;
		for(j=ln;j;j--)
		{
			k=s[j-1]-'a';
			fq[k].fr+=ml;
			if(j==1)
			{
				fq[k].sc=1;
			}
			ml*=10;
		}
	}
	sort(fq,fq+10,greater<pair<long long,bool>>());
	for(i=0;i<10;i++)
	{
		k=fq[i].fr;
		g=fq[i].sc;
		if(!g&&!bad)
		{
			bad=1;
		}
		else
		{
			z+=k*(i+!bad);
		}
	}
	printf("%lld\n",z);
}