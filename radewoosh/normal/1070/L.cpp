#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define dor >debug & operator<< (
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug &>::type operator<< (c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c * x) -> decltype(cerr << *x, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() {cerr << endl;}
eni(==) ris << range(begin(i), end(i));}
eni(!=) cerr << i; ris;}
sim dor rge<c> x) {
	cerr << "[";
	for (c it = x.b; it != x.e; ++it)
		*this << ", " + 2 * (x.b == it) << *it;
	ris << "]";
}
sim, class b dor pair <c,b> x) {ris << "(" << x.first << ", " << x.second << ")";}
#else
sim dor const c&) {ris;}
#endif
};
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) << ": " << a[i] << "] " 
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] " 
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
const int nax=2007;
using bn=bitset<nax>;

int n, m;

bn tab[nax];

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		tab[i].reset();
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		tab[a][b]=1;
		tab[b][a]=1;
	}
	int czy=1;
	for (int i=1; i<=n; i++)
	{
		if (tab[i].count()&1)
		{
			czy=0;
			tab[i][i]=1;
			tab[i][0]=1;
		}
	}
	
	if (czy)
	{
		printf("1\n");
		for (int i=1; i<=n; i++)
			printf("1 ");
		printf("\n");
		return;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i; j<=n; j++)
		{
			if (tab[j][i])
			{
				swap(tab[i], tab[j]);
				break;
			}
		}
		if (!tab[i][i])
			tab[i][i]=1;
		for (int j=1; j<=n; j++)
			if (j!=i && tab[j][i])
				tab[j]^=tab[i];
	}
	printf("2\n");
	for (int i=1; i<=n; i++)
		printf("%d ", tab[i][0]+1);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}