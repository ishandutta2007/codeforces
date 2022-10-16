#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,bc=0,ls[2];
bitset<200069> a[2];
vector<pair<long long,long long>> v;

int main()
{
	long long i,it,z=0;
	string s;
	
	scanf("%lld",&n);
	for(it=0;it<2;it++)
	{
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[it][i]=s[i-1]-'a';
			bc+=a[it][i];
		}
	}
	if(bc%2==1)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(a[0][i]!=a[1][i])
		{
			if(ls[a[0][i]])
			{
				v.push_back(mp(ls[a[0][i]],i));
				if(a[0][i])
				{
					swap(v[z].fr,v[z].sc);
				}
				z++;
				ls[a[0][i]]=0;
			}
			else
			{
				ls[a[0][i]]=i;
			}
		}
	}
	if(ls[0])
	{
		v.push_back(mp(ls[0],ls[0]));
		v.push_back(mp(ls[0],ls[1]));
		z+=2;
	}
	printf("%lld\n",z);
	for(i=0;i<z;i++)
	{
		printf("%lld %lld\n",v[i].fr,v[i].sc);
	}
}