#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,a[100069];
map<string,long long> yk;
string ky[100069];
pair<long long,long long> qq[100069];

int main()
{
	long long i,k,p,mx=0;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		scanf("%lld",&k);
		if(!yk[s])
		{
			nn++;
			ky[nn]=s;
			yk[s]=nn;
		}
		p=yk[s];
		a[p]+=k;
		qq[i]={p,a[p]};
	}
	for(i=1;i<=nn;i++)
	{
		mx=max(mx,a[i]);
	}
	for(i=1;i<=n;i++)
	{
		k=qq[i].sc;
		p=qq[i].fr;
		if(k>=mx&&a[p]==mx)
		{
			printf("%s\n",ky[p].c_str());
			return 0;
		}
	}
}