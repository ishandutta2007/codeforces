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
const int d=5;
const int inf=1e9;

void nope()
{
	printf("-1\n");
}

int n;
char wcz[nax];
int tab[nax];

int po[nax];

int potenga(int v)
{
	return !(v&(v-1));
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//~ mt19937 rng(4);

vi typy;

int ocen(int v)
{
	int ret=inf;
	for (int i : typy)
		ret=min(ret, abs(v-i));
	return ret;
}

void brut()
{
	//jesli zylowac
}

//~ ll prasum()
//~ {
	//~ ll ret=0;
	//~ ll pen=0;
	//~ for (int i=1; i<=n; i++)
	//~ {
		//~ pen=2*pen+tab[i];
		//~ if (po[i])
		//~ {
			//~ ret+=pen;
			//~ pen=0;
		//~ }
	//~ }
	//~ return ret+pen;
//~ }

void test()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'0';
	int ile=0;
	for (int i=1; i<=n; i++)
		ile+=tab[i];
	if (!ile)
	{
		nope();
		return;
	}
	if (potenga(ile))
	{
		printf("%d\n", n);
		for (int i=1; i<=n; i++)
			printf("%d %d\n", i, i);
		return;
	}
	typy.clear();
	for (int i=ile; (int)typy.size()<3; i++)
		if (potenga(i))
			typy.push_back(i);
	//~ if (n<=10)
		//~ brut();
	for (int i=0; i<=n; i++)
		po[i]=1;
	int teraz=ile;
	vi inter;
	for (int i=1; i<n; i++)
	{
		int ok=0;
		for (int j=0; j<d && j<i; j++)
			if (tab[i-j])
				ok=1;
		if (ok)
			inter.push_back(i);
	}
	assert(!inter.empty());
	while(1)
	{
		for (int chce : typy)
		{
			ll kroki=n*100+300;
			while(kroki>0 && !potenga(teraz))
			{
				kroki--;
				int x=inter[rng()%inter.size()];
				int l=x-1;
				int p=x+1;
				while(!po[l])
					l--;
				while(!po[p])
					p++;
				if (po[x] && p-l>d)
					continue;
				int delta=0;
				if (po[x])
				{
					for (int i=x; i>l; i--)
						if (tab[i])
							delta+=(1<<(p-i))-(1<<(x-i));
				}
				else
				{
					for (int i=x; i>l; i--)
						if (tab[i])
							delta+=(1<<(x-i))-(1<<(p-i));
				}
				if (abs(teraz+delta-chce)<=abs(teraz-chce) || !(rng()%50))
				{
					teraz+=delta;
					po[x]^=1;
				}
			}
			if (potenga(teraz))
			{
				vi cie{0};
				for (int i=1; i<=n; i++)
					if (po[i])
						cie.push_back(i);
				int r=cie.size()-1;
				printf("%d\n", r);
				for (int i=1; i<=r; i++)
				{
					int a=cie[i-1]+1;
					int b=cie[i];
					printf("%d %d\n", a, b);
				}
				return;
			}
		}
	}
	nope();
}

int main()
{
	//~ for (int i=1; i<=100000; i++)
	//~ {
		//~ if (!(i%1000))
			//~ debug() << i;
		//~ int umiem=0;
		//~ for (int a=0; 3*a<=i && !umiem; a++)
		//~ {
			//~ for (int b=0; 3*a+2*b<=i && !umiem; b++)
			//~ {
				//~ int c=i-3*a-2*b;
				//~ if (potenga(7*a+3*b+1*c))
					//~ umiem=1;
			//~ }
		//~ }
		//~ if (!umiem)
			//~ debug() << "nie umiem " << i;
	//~ }
	
	//~ return 0;
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}