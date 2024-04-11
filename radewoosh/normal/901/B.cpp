//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
ll mod=1000*1000*1000+7;

void oczy(vector <ll> &wek)
{
	while(!wek.empty() && !wek.back())
		wek.pop_back();
}

ll dziel(ll a, ll b)
{
	ll wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
			a=(a*b)%mod;
		b=(b*b)%mod;
		wyk>>=1;
	}
	return a;
}

vector <ll> moduj(vector <ll> jed, vector <ll> dwa)
{
	oczy(jed);
	oczy(dwa);
	if (jed.size()<dwa.size())
		return jed;
	for (int i=0; i<(int)dwa.size(); i++)
		jed[i+(int)jed.size()-(int)dwa.size()]=((jed[i+(int)jed.size()-(int)dwa.size()]-dziel(jed.back(), dwa.back())*dwa[i])%mod+mod)%mod;
	return moduj(jed, dwa);
}

int euk(vector <ll> jed, vector <ll> dwa)
{
	oczy(jed);
	oczy(dwa);
	if (dwa.empty())
		return 0;
	//debug() << "jade " << jed << " " << dwa;
	return 1+euk(dwa, moduj(jed, dwa));
}

int main()
{
	int n;
	scanf("%d", &n);
	while(1)
	{
		mod=1000*1000*1000+7;
		vector <ll> jed, dwa;
		for (int i=0; i<n; i++)
		{
			jed.push_back((rand()%3)-1);
			if (i)
				dwa.push_back((rand()%3)-1);
		}
		jed.push_back(1);
		dwa.push_back(1);
		if (euk(jed, dwa)==n)
		{
			mod+=2;
			if (euk(jed, dwa)!=n)
				continue;
			printf("%d\n", n);
			for (ll i : jed)
				printf("%lld ", i);
			printf("\n");
			printf("%d\n", n-1);
			for (ll i : dwa)
				printf("%lld ", i);
			printf("\n");
			return 0;
		}
	}
	return 0;
}