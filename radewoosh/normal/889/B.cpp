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
const int d=26;

void nope()
{
	printf("NO\n");
	exit(0);
}

int n;
string tab[nax];

char wcz[nax];

string wczyt()
{
	string ret="";
	scanf("%s", wcz);
	for (int i=0; wcz[i]; i++)
		ret.push_back(wcz[i]);
	return ret;
}

set <int> graf[nax];
set <int> farg[nax];

int tak[nax];

string wyn;

void dfs(int v)
{
	tak[v]=0;
	wyn.push_back('a'+v);
	for (int i : graf[v])
		dfs(i);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		tab[i]=wczyt();
		set <int> tutaj;
		for (int j=0; j+1<(int)tab[i].size(); j++)
		{
			graf[tab[i][j]-'a'].insert(tab[i][j+1]-'a');
			farg[tab[i][j+1]-'a'].insert(tab[i][j]-'a');
		}
		for (int j=0; j<(int)tab[i].size(); j++)
			tak[tab[i][j]-'a']=1;
	}
	for (int i=0; i<d; i++)
		if ((int)graf[i].size()>1 || (int)farg[i].size()>1)
			nope();
	for (int i=0; i<d; i++)
		if (farg[i].empty() && tak[i])
			dfs(i);
	for (int i=0; i<d; i++)
		if (tak[i])
			nope();
	cout << wyn << endl;
	return 0;
}