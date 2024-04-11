#include <bits/stdc++.h>
using namespace std;

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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

const int nax=1007*1007;
const int sax=67;

int n;

vector <int> spr;

int xo;

/*int czy_zaw(vector <int> &wek, int v)
{
	for (int i=0; i<wek.size(); i++)
		if (wek[i]==v)
			return 1;
	return 0;
}

int licz(int v, vector <int> wek)
{
	if (!v)
		return 0;
	vector <int> zak;
	for (int i=0; i<=v+2; i++)
		zak.push_back(0);
	vector <int> pom;
	for (int i=1; i<=v; i++)
	{
		if (czy_zaw(wek, i))
			continue;
		pom=wek;
		pom.push_back(i);
		zak[licz(v-i, pom)]=1;
	}
	for (int i=0; 1; i++)
		if (!zak[i])
			return i;
}*/

int main()
{
	/*for (int i=0; i<sax; i++)
	{
		spr[i]=licz(i, vector<int>{});
		debug() << i << " " << spr[i];
	}
	debug() << range(spr, spr+sax);
	return 0;*/
	for (int i=0; i<=100; i++)
		for (int j=0; j<=i; j++)
			spr.push_back(i);
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		int p1;
		scanf("%d", &p1);
		xo^=spr[p1];
	}
	if (xo)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}