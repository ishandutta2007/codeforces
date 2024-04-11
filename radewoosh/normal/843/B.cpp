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

const int nax=50*1007;

int n;

int sta;
int lim;

vector <pair <int,int> > wek;

void zrob(int v)
{
	while(1)
	{
		if (v==-1)
		{
			printf("! -1\n");
			fflush(stdout);
			exit(0);
		}
		printf("? %d\n", v);
		fflush(stdout);
		int a, b;
		scanf("%d%d", &a, &b);
		if (a>=lim)
		{
			printf("! %d\n", a);
			fflush(stdout);
			exit(0);
		}
		v=b;
	}
}

vector <long long> wez{213123, 1434265, 124235, 357567, 3245324, 124234, 3645764, 124235423, 35466346, 2342345, 346536, 23452345, 23542353, 53245345, 3456345634, 34563453, 245234, 6457568, 345345, 234234, 234236, 6534645};

long long los()
{
    if (!wez.empty())
    {
        long long x=wez.back();
        wez.pop_back();
        return x;
    }
	long long ret=rand();
	ret*=nax;
	ret+=rand();
	return ret;
}

int main()
{
	srand(time(0));
	scanf("%d%d%d", &n, &sta, &lim);
	for (int h=1; h<=1500; h++)
	{
		int x=(los()%n)+1;
		if (h==1)
			x=sta;
		printf("? %d\n", x);
		fflush(stdout);
		int a, b;
		scanf("%d%d", &a, &b);
		wek.push_back({a, x});
	}
	sort(wek.begin(), wek.end());
	if (wek[0].first>=lim)
	{
		printf("! %d\n", wek[0].first);
		fflush(stdout);
		return 0;
	}
	for (int i=0; i<(int)wek.size(); i++)
		if (i+1==wek.size() || wek[i+1].first>lim)
			zrob(wek[i].second);
	return 0;
}