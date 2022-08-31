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

const int nax=107;

int n, m;
int wol[nax][nax];
char wcz[nax];

pair <int,int> sta, kon;

int wyn;

int rx[]={-1, 1, 0, 0};
int ry[]={0, 0, -1, 1};

vector <int> ruch;

int per[nax];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
		{
			if (wcz[j]=='#')
				continue;
			wol[i][j]=1;
			if (wcz[j]=='S')
				sta={i, j};
			if (wcz[j]=='E')
				kon={i, j};
		}
	}
	scanf("%s", wcz);
	for (int i=0; wcz[i]; i++)
		ruch.push_back(wcz[i]-'0');
	
	for (int i=0; i<4; i++)
		per[i]=i;
	for (int h=0; h<24; h++)
	{
		next_permutation(per, per+4);
		auto ter=sta;
		for (int i : ruch)
		{
			ter.first+=rx[per[i]];
			ter.second+=ry[per[i]];
			if (!wol[ter.first][ter.second])
				break;
			if (ter==kon)
			{
				wyn++;
				break;
			}
		}
	}
	
	printf("%d\n", wyn);
	return 0;
}