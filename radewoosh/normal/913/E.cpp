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

const int nax=256;

string odp[nax][5];
//0-nawias
//1-mno
//2-dod

int czy;

inline void cons(const string &s, int v, int u)
{
	if (u==3)
		return;
	if (odp[v][u].empty() || (int)s.size()<(int)odp[v][u].size() || ((int)s.size()==(int)odp[v][u].size() &&  s<odp[v][u]))
	{
		czy=1;
		odp[v][u]=s;
		//~ debug() << v << " " << u << " to " << s;
	}
	cons(s, v, u+1);
}

void test()
{
	string s;
	cin >> s;
	int w=0;
	for (int i=0; i<8; i++)
		w+=((s[i]-'0')<<i);
	cout << odp[w][2] << "\n";
}



int main()
{
	cons("x", 16+32+64+128, 0);
	cons("y", 4+8+64+128, 0);
	cons("z", 2+8+32+128, 0);
	while(czy)
	{
		czy=0;
		for (int i=0; i<nax; i++)
		{
			for (int ii=0; ii<3; ii++)
			{
				if (odp[i][ii].empty())
					continue;
				cons("("+odp[i][ii]+")", i, 0);
				if (!ii)
					cons("!"+odp[i][ii], i^(nax-1), 0);
				for (int j=0; j<nax; j++)
				{
					for (int jj=0; jj<3; jj++)
					{
						if (odp[j][jj].empty())
							continue;
						if (ii<=1 && jj<=1)
							cons(odp[i][ii]+"&"+odp[j][jj], i&j, 1);
						if (ii<=2 && jj<=2)
							cons(odp[i][ii]+"|"+odp[j][jj], i|j, 2);
					}
				}
			}
		}
	}
	debug() << "ok";
	
	int t;
	cin >> t;
	while(t--)
		test();
	return 0;
}