//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
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
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
const ll inf=1e18;

void ff()
{
	fflush(stdout);
}

int n;
ll a, b, c;

char wcz[nax];

ll wyn;

void test()
{
	scanf("%d%lld%lld%lld", &n, &a, &b, &c);
	scanf("%s", wcz+1);
	wyn=0;
	int zer=0;
	int jed=0;
	int dzer=0;
	int djed=0;
	vector<pii> prz;
	for (int i=1; i<=n; i++)
	{
		int x=wcz[i]-'0';
		if (prz.empty() || prz.back().first!=x)
			prz.push_back({x, 0});
		prz.back().second++;
	}
	vi wek;
	int id=-1;
	for (pii i : prz)
	{
		id++;
		if (i.first==0 && id!=0 && id!=(int)prz.size()-1)
			wek.push_back(i.second);
	}
	sort(wek.begin(), wek.end());
	reverse(wek.begin(), wek.end());
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]!=wcz[i-1])
		{
			if (wcz[i]=='0')
				zer++;
			else
				jed++;
		}
		else
		{
			if (wcz[i]=='0')
				dzer++;
			else
				djed++;
		}
	}
	//~ while(dzer>0 && djed>0)
	//~ {
		//~ dzer--;
		//~ djed--;
		//~ wyn+=a+b;
	//~ }
	ll naj=0;
	for (int h=0; h<2; h++)
	{
		vll kop{zer, jed, dzer, djed};
		vi sukop=wek;
		
		ll ter=0;
		int zapas=0;
		for (int i=1; 1; i++)
		{
			if ((i&1)==h)
			{
				if (djed==0 && !wek.empty() && zapas>=wek.back())
				{
					jed--;
					djed++;
					dzer++;
					zer--;
					ter-=a;
					ter-=c;
					zapas-=wek.back();
					wek.pop_back();
				}
				if (djed>0)
				{
					djed--;
					ter+=b;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (dzer>0)
				{
					dzer--;
					ter+=a;
					zapas++;
				}
				else
				{
					if (zer>0)
					{
						wek.clear();
						zer--;
						ter-=c;
						if (jed>1)
						{
							jed--;
							djed++;
						}
					}
					else
					{
						break;
					}
				}
			}
			naj=max(naj, ter);
		}
		
		
		zer=kop[0];
		jed=kop[1];
		dzer=kop[2];
		djed=kop[3];
		wek=sukop;
	}
	printf("%lld\n", wyn+naj);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}