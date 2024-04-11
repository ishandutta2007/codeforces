#include <iostream>
#include <set>

using namespace std;

int main()
{
	long long W,H,n,i,k;
	char ch;
	set<long long> v,h;
	multiset<long long> vv,hh;
	set<long long>::iterator it;
	
	scanf("%lld%lld%lld",&W,&H,&n);
	v.insert(0);
	v.insert(W);
	vv.insert(W);
	h.insert(0);
	h.insert(H);
	hh.insert(H);
	for(i=0;i<n;i++)
	{
		scanf(" %c%lld",&ch,&k);
		if(ch=='V')
		{
			it=v.lower_bound(k);
			it--;
			vv.erase(vv.lower_bound(*v.lower_bound(k)-(*it)));
			v.insert(k);
			vv.insert(*v.upper_bound(k)-k);
			vv.insert(k-*it);
		}
		else if(ch=='H')
		{
			it=h.lower_bound(k);
			it--;
			hh.erase(hh.lower_bound(*h.lower_bound(k)-(*it)));
			h.insert(k);
			hh.insert(*h.upper_bound(k)-k);
			hh.insert(k-*it);
		}
		printf("%lld\n",(*vv.rbegin())*(*hh.rbegin()));
	}
}