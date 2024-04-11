//while (clock()<=69*CLOCKS_PER_SEC)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

const int nax=100*1007;

long long seed, vmax;

long long rnd()
{
    long long ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

struct prze
{
	int l, p;
	long long x;
	prze(){}
	prze(int ll, int pp, long long xx)
	{
		l=ll;
		p=pp;
		x=xx;
	}
	void wyp()
	{
		debug() << l << " " << p << " " << x;
	}
};

bool operator < (prze a, prze b)
{
	if (a.l!=b.l)
		return a.l<b.l;
	return a.p<b.p;
}

long long pot(long long a, long long b, long long mod)
{
	a%=mod;
	long long ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret%mod;
}

int n, m;

set <prze> setel;

void cut(int v)
{
	auto it=setel.lower_bound(prze(v, n+3, -1));
	it--;
	if ((*it).p==v)
		return;
	auto war=(*it);
	setel.erase(it);
	setel.insert(prze(war.l, v, war.x));
	setel.insert(prze(v+1, war.p, war.x));
}

vector <prze> wek;

bool mniej(prze a, prze b)
{
	return a.x<b.x;
}

void zbierz(int l, int r)
{
	wek.clear();
	cut(l-1);
	cut(r);
	auto it=setel.lower_bound(prze(l, -1, -1));
	while((*it).l<=r)
	{
		wek.push_back(*it);
		it++;
	}
}

int main()
{
	scanf("%d%d%lld%lld", &n, &m, &seed, &vmax);
	setel.insert(prze(0, 0, 0));
	setel.insert(prze(n+1, n+1, 0));
	for (int i=1; i<=n; i++)
		setel.insert(prze(i, i, (rnd()%vmax)+1));
	//for (auto i : setel)
	//	i.wyp();
	while(m--)
	{
		
		int op = (rnd() % 4) + 1;
		int l = (rnd() % n) + 1;
		int r = (rnd() % n) + 1;
		
		int x, y;
		
		if (l > r)
			 swap(l, r);

		if (op == 3)
			x = (rnd() % (r - l + 1)) + 1;
		else
			x = (rnd() % vmax) + 1;

		if (op == 4)
			y = (rnd() % vmax) + 1;
		
		zbierz(l, r);
		
		//debug() << op;
		if (op==1)
		{
			//debug() << l << " " << r << " " << x;
			for (prze i : wek)
			{
				setel.erase(i);
				setel.insert(prze(i.l, i.p, i.x+x));
			}
		}
		if (op==2)
		{
			//debug() << l << " " << r << " " << x;
			for (prze i : wek)
				setel.erase(i);
			setel.insert(prze(l, r, x));
		}
		if (op==3)
		{
			//debug() << l << " " << r << " " << x;
			sort(wek.begin(), wek.end(), mniej);
			for (prze i : wek)
			{
				if (x<=i.p-i.l+1)
				{
					printf("%lld\n", i.x);
					break;
				}
				x-=(i.p-i.l+1);
			}
		}
		if (op==4)
		{
			//debug() << l << " " << r << " " << x << " " << y;
			long long sum=0;
			for (prze i : wek)
				sum=(sum+(i.p-i.l+1)*pot(i.x, x, y))%y;
			printf("%lld\n", sum);
		}
	}
	return 0;
}