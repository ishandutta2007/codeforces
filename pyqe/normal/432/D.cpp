#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],faf[100069],fq[100069],zs=0;
vector<pair<long long,long long>> sq;

int main()
{
	long long i,j;
	string s;
	
	cin>>s;
	n=s.length();
	faf[0]=-1;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'A';
		for(j=i-1;j&&a[faf[j]+1]!=a[i];j=faf[j]);
		faf[i]=faf[j]+1;
		fq[i]=1;
	}
	for(i=n;i;i--)
	{
		fq[faf[i]]+=fq[i];
	}
	for(i=n;i;i=faf[i])
	{
		sq.push_back({i,fq[i]});
		zs++;
	}
	printf("%lld\n",zs);
	for(i=zs-1;i>=0;i--)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}