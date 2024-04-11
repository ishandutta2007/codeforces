#include <bits/stdc++.h>

using namespace std;

long long n;

#define mp make_pair
#define fr first
#define sc second

struct trie
{
	long long n=0,c=0;
	trie *pr;
	multiset<pair<long long,trie*>> cd;
}
*tr;

int main()
{
	long long t,rr,i,k,z;
	multiset<pair<long long,trie*>>::iterator it;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		tr=new trie;
		tr->c++;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(k!=tr->n)
			{
				it=tr->cd.lower_bound({k,0});
				if(it==tr->cd.end()||it->fr!=k)
				{
					tr->cd.insert({k,new trie});
					it=tr->cd.lower_bound({k,0});
					it->sc->n=k;
					it->sc->pr=tr;
				}
				tr=it->sc;
			}
			else
			{
				tr=tr->pr;
			}
			z+=tr->c;
			tr->c++;
		}
		printf("%lld\n",z);
	}
}