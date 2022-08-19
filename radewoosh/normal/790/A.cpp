//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

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

const int nax=107;

int n, k;

string wer[nax];

string wyn[nax];

int main()
{
	cin >> n >> k;
	for (int i=0; i<n-k+1; i++)
		cin >> wer[i];
	for (int i=0; i<n; i++)
	{
		if (i<26)
		{
			wyn[i]+=(char)('A'+i);
		}
		else
		{
			wyn[i]+=(char)('A'+i-26);
			wyn[i]+=(char)('a');
		}
	}
	for (int i=0; i<n-k+1; i++)
		if (wer[i][0]=='N')
			wyn[i+k-1]=wyn[i];
	for (int i=0; i<n; i++)
		cout << wyn[i] << " ";
	cout << endl;
	return 0;
}