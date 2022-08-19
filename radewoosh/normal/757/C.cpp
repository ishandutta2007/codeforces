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

int n, m;

long long hasz1[1000007];
long long hasz2[1000007];
long long gym1[1000007];
long long gym2[1000007];

long long wyn=1;
long long mod=1000000007;

vector < pair <long long,long long> > wek;

int main()
{
	srand(time(0));
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=12; j++)
			hasz1[i]=hasz1[i]*10+(rand()%10);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=12; j++)
			hasz2[i]=hasz2[i]*10+(rand()%10);
	for (int i=1; i<=n; i++)
	{
		int p1, p2;
		scanf("%d", &p1);
		while(p1--)
		{
			scanf("%d", &p2);
			gym1[p2]+=hasz1[i];
			gym2[p2]+=hasz2[i];
		}
	}
	for (int i=1; i<=m; i++)
		wek.push_back({gym1[i], gym2[i]});
	sort(wek.begin(), wek.end());
	int l;
	for (int i=0; i<m; i++)
	{
		if (!i || wek[i]!=wek[i-1])
			l=0;
		l++;
		wyn*=l;
		wyn%=mod;
	}
	printf("%lld\n", wyn);
	return 0;
}