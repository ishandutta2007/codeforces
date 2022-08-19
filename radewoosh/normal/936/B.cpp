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
const int nax=1000*1007;

int n, m;
vector <int> graf[nax];
vector <int> farg[nax];

int s;

int bylo[nax][2];

vector <int> stos;

int juz[nax];

void dfs(int v, int p)
{
	if (bylo[v][p])
		return;
	bylo[v][p]=1;
	stos.push_back(v);
	if (v==s && p)
	{
		printf("Win\n");
		while(!stos.empty())
		{
			printf("%d ", stos.back());
			stos.pop_back();
		}
		printf("\n");
		exit(0);
	}
	for (int i : farg[v])
		dfs(i, p^1);
	
	stos.pop_back();
}

void dfs2(int v)
{
	if (juz[v]==2)
		return;
	if (juz[v]==1)
	{
		printf("Draw\n");
		exit(0);
	}
	juz[v]=1;
	for (int i : graf[v])
		dfs2(i);
	juz[v]=2;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		int x, y;
		scanf("%d", &x);
		while(x--)
		{
			scanf("%d", &y);
			graf[i].push_back(y);
			farg[y].push_back(i);
		}
	}
	scanf("%d", &s);
	for (int i=1; i<=n; i++)
		if (graf[i].empty())
			dfs(i, 0);
	dfs2(s);
	printf("Lose\n");
	return 0;
}