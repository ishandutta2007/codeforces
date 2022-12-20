#include <iostream>
#include <map>
using namespace std;

map<long long,long long> M;

int Q;

void inc(long long p,int w)
{
	if(p==1) return;
	M[p] += w;
	inc(p/2,w);
}

long long getSum(long long p)
{
	if(p==1) return 0;
	return M[p]+getSum(p/2);
}

long long lca(long long a,long long b)
{
	while(1)
	{
		for(int i=0;i<63;i++)
			if((b>>i)==a)
				return a;
		a /= 2;
	}
}

int main()
{
	cin >> Q;
	int tp;
	long long u,v;
	int w;
	for(int i=0;i<Q;i++)
	{
		cin >> tp >> u >> v;
		long long l = lca(u,v);
		if(tp==1)
		{
			cin >> w;
			inc(u,w);
			inc(v,w);
			inc(l,-2*w);
		}
		else
			cout << getSum(u)+getSum(v)-2*getSum(l) << '\n';
	}
}