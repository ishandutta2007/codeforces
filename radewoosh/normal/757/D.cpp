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

int n;

char wcz[107];

int tab[107][107];

int mod=1000000007;

int k=20;

int dp[77][1100007];

int suma[1100007];

int wyn;

inline void dodaj(int &a, int b)
{
	a+=b;
	if (a>=mod)
		a-=mod;
}

int dobry(int v)
{
	int czyzer=0;
	while(v)
	{
		if (v&1)
		{
			if (czyzer)
				return 0;
		}
		else
		{
			czyzer=1;
		}
		v>>=1;
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			tab[i][j]=tab[i][j-1]*2+(wcz[j]-'0');
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			tab[i][j]--;
	for (int i=0; i<=n; i++)
		dodaj(dp[i][0], 1);
	for (int i=1; i<=n; i++)
	{
		for (int j=i; j<=n && tab[i][j]<k; j++)
		{
			if (tab[i][j]==-1)
				continue;
			for (int l=0; l<(1<<k); l++)
				dodaj(dp[j][l|(1<<tab[i][j])], dp[i-1][l]);
		}
		for (int l=0; l<(1<<k); l++)
			dodaj(suma[l], dp[i][l]);
	}
	for (int i=1; i<(1<<k); i++)
		if (dobry(i))
			dodaj(wyn, suma[i]);
	printf("%d\n", wyn);
	return 0;
}