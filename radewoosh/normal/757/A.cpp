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
sim dor(c) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

string s="Bulbasaur";
string w;

int wym[1000007];
int ile[100007];

int wyn=1000000000;

int main()
{
	cin >> w;
	for (int i=0; i<s.size(); i++)
		wym[s[i]]++;
	for (int i=0; i<w.size(); i++)
		ile[w[i]]++;
	for (int i=1; i<=1000; i++)
		if (wym[i])
			wyn=min(wyn, ile[i]/wym[i]);
	printf("%d\n", wyn);
	return 0;
}