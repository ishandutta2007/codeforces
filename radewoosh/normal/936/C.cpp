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

using ll=long long;
const int nax=2007;

int n;

char slo[2][nax];

vector < pair <char,int> > raz, dwa;

int per[nax];

vector <int> wyn;

void zrob(int v)
{
	wyn.push_back(v);
	vector <int> wek;
	for (int i=1; i<=v; i++)
		wek.push_back(per[n+1-i]);
	for (int i=n; i>v; i--)
		per[i]=per[i-v];
	for (int i=0; i<v; i++)
		per[i+1]=wek[i];
}

int main()
{
	scanf("%d", &n);
	scanf("%s", slo[0]+1);
	scanf("%s", slo[1]+1);
	for (int i=1; i<=n; i++)
		raz.push_back({slo[0][i], i});
	for (int i=1; i<=n; i++)
		dwa.push_back({slo[1][i], i});
	sort(raz.begin(), raz.end());
	sort(dwa.begin(), dwa.end());
	for (int i=0; i<n; i++)
	{
		if (raz[i].first!=dwa[i].first)
		{
			printf("-1\n");
			return 0;
		}
		per[raz[i].second]=dwa[i].second;
	}
	int sr=(n+1)/2;
	for (int i=1; i<n; i++)
	{
		debug() << range(per+1, per+1+n);
		if (i&1)
		{
			for (int j=1; j<=n; j++)
			{
				if (per[j]==sr+(i/2))
				{
					zrob(n-j);
					break;
				}
			}
			for (int j=1; j<=n; j++)
			{
				if (per[j]==sr+(i/2)+1)
				{
					zrob(n-j);
					zrob(1);
					break;
				}
			}
		}
		else
		{
			for (int j=1; j<=n; j++)
			{
				if (per[j]==sr-((i-1)/2))
				{
					zrob(n-j);
					break;
				}
			}
			for (int j=1; j<=n; j++)
			{
				if (per[j]==sr-((i-1)/2)-1)
				{
					zrob(n-j);
					zrob(1);
					break;
				}
			}
		}
	}
	debug() << range(per+1, per+1+n);
	if (per[1]==n)
		zrob(n);
	debug() << range(per+1, per+1+n);
	printf("%d\n", (int)wyn.size());
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
	return 0;
}