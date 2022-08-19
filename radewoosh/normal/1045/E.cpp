//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const int nax=1007;
const ll mod=1000*1000*1000+7;

int n;

pii tab[nax];
int kol[nax];

int dos[nax];

pii operator - (pii a, pii b)
{
	return {a.first-b.first, a.second-b.second};
}

int ilowek(int s, int a, int b)
{
	pii x=tab[a]-tab[s];
	pii y=tab[b]-tab[s];
	return x.first*y.second-x.second*y.first;
}

bool mniej1(int a, int b)
{
	return tab[a]<tab[b];
}

bool mniej2(int a, int b)
{
	return ilowek(dos[1], a, b)>0;
}

void nope()
{
	printf("Impossible\n");
	exit(0);
}

int znak(int v)
{
	if (!v)
		return 0;
	return v/abs(v);
}

int czyzaw(int a, int b, int c, int s)
{
	int w=znak(ilowek(a, b, s))+znak(ilowek(b, c, s))+znak(ilowek(c, a, s));
	return (abs(w)==3);
}

void pisz(int a, int b)
{
	printf("%d %d\n", a-1, b-1);
}

void lacz(int a, int b, int c)
{
	assert(kol[a]==kol[b]);
	assert(kol[a]!=kol[c]);
	vi wek;
	for (int i=1; i<=n; i++)
		if (czyzaw(a, b, c, i))
			wek.push_back(i);
	for (int i : wek)
	{
		if (kol[i]==kol[c])
		{
			pisz(i, c);
			lacz(a, b, i);
			lacz(c, i, a);
			lacz(c, i, b);
			return;
		}
	}
	for (int i : wek)
		pisz(a, i);
}

int ile[2];
	
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d%d", &tab[i].first, &tab[i].second, &kol[i]);
		ile[kol[i]]++;
		dos[i]=i;
	}
	if (!ile[0] || !ile[1])
	{
		printf("%d\n", n-1);
		for (int i=1; i<n; i++)
			printf("%d %d\n", 0, i);
		return 0;
	}
	if (n==2)
	{
		printf("0\n");
		return 0;
	}
	sort(dos+1, dos+1+n, mniej1);
	sort(dos+2, dos+1+n, mniej2);
	vi oto;
	for (int i=1; i<=n; i++)
	{
		int v=dos[i];
		int r=oto.size();
		while(r>1 && ilowek(oto[r-2], oto[r-1], v)<0)
		{
			oto.pop_back();
			r--;
		}
		oto.push_back(v);
	}
	debug() << oto;
	ile[0]=ile[1]=0;
	for (int i : oto)
		ile[kol[i]]++;
	if (ile[0] && ile[1])
	{
		for (int i=1; i<(int)oto.size(); i++)
		{
			if (kol[oto[i]]!=kol[oto[i-1]])
			{
				vi pom=oto;
				oto.clear();
				for (int j=0; j<(int)pom.size(); j++)
					oto.push_back(pom[(i+j)%pom.size()]);
				break;
			}
		}
		int zm=0;
		for (int i=1; i<(int)oto.size(); i++)
			if (kol[oto[i]]!=kol[oto[i-1]])
				zm++;
		if (zm>1)
			nope();
	}
	printf("%d\n", n-2);
	if (!ile[0] || !ile[1])
	{
		for (int i=1; i<(int)oto.size(); i++)
			pisz(oto[i], oto[i-1]);
		for (int i=1; i<=n; i++)
		{
			if (kol[i]!=kol[oto[0]])
			{
				for (int j=0; j<(int)oto.size(); j++)
					lacz(oto[j], oto[(j+1)%oto.size()], i);
				break;
			}
		}
	}
	else
	{
		for (int i=1; i<(int)oto.size(); i++)
			if (kol[oto[i]]==kol[oto[i-1]])
				pisz(oto[i], oto[i-1]);
		int gdz=-1;
		for (int i=1; i<(int)oto.size(); i++)
			if (kol[oto[i]]!=kol[oto[i-1]])
				gdz=i;
		for (int i=1; i<gdz; i++)
			lacz(oto[i-1], oto[i], oto[gdz]);
		for (int i=gdz+1; i<(int)oto.size(); i++)
			lacz(oto[i-1], oto[i], oto[0]);
	}
	
	return 0;
}