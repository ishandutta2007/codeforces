#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,pr[300069],d[4];
vector<long long> al;
map<pair<long long,long long>,bool> fq;
pair<long long,long long> a[300069];

int main()
{
	long long i,k,l,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		if(k==1)
		{
			al.push_back(l);
		}
		fq[{k,l}]=1;
		a[i]={k,l};
	}
	for(i=1;i<=n;i++)
	{
		pr[i]=1;
	}
	sort(al.begin(),al.end());
	sz=al.size();
	for(i=0;i<sz;i++)
	{
		l=al[i];
		if(!fq[{al[0],l}])
		{
			pr[l]=2;
			d[2]++;
		}
		else
		{
			pr[l]=3;
			d[3]++;
		}
	}
	d[1]=n-d[2]-d[3];
	if(!d[1]||!d[2]||!d[3]||m!=d[1]*d[2]+d[2]*d[3]+d[3]*d[1])
	{
		printf("-1\n");
		return 0;
	}
	for(i=0;i<m;i++)
	{
		if(pr[a[i].fr]==pr[a[i].sc])
		{
			printf("-1\n");
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",pr[i]," \n"[i==n]);
	}
}