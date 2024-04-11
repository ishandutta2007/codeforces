#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,zs;
bool a[2069];
vector<pair<long long,long long>> sq;

int main()
{
	long long t,rr,i,ii,j,k;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		cin>>s;
		for(i=0;i<n;i++)
		{
			a[i]=s[i]==')';
		}
		sq.clear();
		zs=0;
		for(i=0;i<d-1;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				for(j=i*2+ii;a[j]!=ii;j++);
				sq.push_back({i*2+ii,j});
				zs++;
				k=j;
				for(j=i*2+ii;j<k-j+i*2+ii;j++)
				{
					swap(a[j],a[k-j+i*2+ii]);
				}
			}
		}
		for(i=d*2-2;i<d*2-2+(n-d*2+2)/2;i++)
		{
			for(j=i;a[j];j++);
			sq.push_back({i,j});
			zs++;
			k=j;
			for(j=i;j<k-j+i;j++)
			{
				swap(a[j],a[k-j+i]);
			}
		}
		printf("%lld\n",zs);
		for(i=0;i<zs;i++)
		{
			printf("%lld %lld\n",sq[i].fr+1,sq[i].sc+1);
		}
	}
}