#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,dv=1e9+7;
pair<long long,long long> as[1000069];
multiset<long long> ms;
multiset<long long>::iterator it;

long long ar(long long x,long long y)
{
	return (x*y+d*(y*(y-1)/2%dv))%dv;
}

int main()
{
	long long i,k,p,lb,rb,ln,dh,z=0;
	
	scanf("%lld%lld",&n,&d);
	d--;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&as[i].fr);
		as[i].sc=i;
	}
	sort(as+1,as+n+1,greater<pair<long long,long long>>());
	ms.insert(0);
	ms.insert(n+1);
	for(i=1;i<=n;i++)
	{
		k=as[i].fr;
		p=as[i].sc;
		it=ms.upper_bound(p);
		rb=(*it);
		it--;
		lb=(*it);
		ln=rb-lb-1;
		dh=(ln-1)/d+1;
		z=(z+k*(ar(1,dh)+dv-ar(d-(rb-p-1)%d,dh-(rb-p-1)/d-1)+dv-ar(d-(p-lb-1)%d,dh-(p-lb-1)/d-1)+dv-1))%dv;
		ms.insert(p);
	}
	printf("%lld\n",z);
}