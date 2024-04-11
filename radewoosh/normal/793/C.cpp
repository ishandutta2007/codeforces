//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

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

const int nax=1000*1007;

int n;

long long x, y;
long long a, b;

vector < pair < long long, long long> > dol;
vector < pair < long long, long long> > gor;

bool mniej(pair < long long, long long> a, pair < long long, long long> b)
{
	return a.first*b.second<b.first*a.second;
}

void nope()
{
	printf("-1\n");
	exit(0);
}

int main()
{
	scanf("%d", &n);
	scanf("%lld%lld", &x, &y);
	scanf("%lld%lld", &a, &b);
	dol.push_back({0, 1});
	for (int i=1; i<=n; i++)
	{
		long long px, py;
		long long zx, zy;
		scanf("%lld%lld", &px, &py);
		scanf("%lld%lld", &zx, &zy);
		for (int h=0; h<2; h++)
		{
			if (px<=x && zx<=0)
				nope();
			if (px>=a && zx>=0)
				nope();
			if (px>x && px<a)
			{
				if (zx>0)
				{
					gor.push_back({a-px, zx});
				}
				if (zx<0)
				{
					gor.push_back({px-x, -zx});
				}
			}
			else
			{
				if (px<=x)
				{
					dol.push_back({x-px, zx});
					gor.push_back({a-px, zx});
				}
				else
				{
					dol.push_back({px-a, -zx});
					gor.push_back({px-x, -zx});
				}
			}
			
			swap(x, y);
			swap(a, b);
			swap(px, py);
			swap(zx, zy);
		}
	}
	sort(dol.begin(), dol.end(), mniej);
	sort(gor.begin(), gor.end(), mniej);
	if (gor.empty() || mniej(dol.back(), gor[0]))
		printf("%.9lf\n", (double)dol.back().first/dol.back().second);
	else
		nope();
	return 0;
}