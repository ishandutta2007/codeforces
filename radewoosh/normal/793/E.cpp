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

const int nax=5007;

int n, k;

int a, b, c, d;

vector <int> graf[nax];
int oj[nax];

int roz[nax];

int ra, rb, rc, rd;

vector <int> wek;

bitset <nax> ple, plec, pled;

int zaj[nax];

int main()
{
	scanf("%d", &n);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for (int i=2; i<=n; i++)
	{
		scanf("%d", &oj[i]);
		graf[oj[i]].push_back(i);
	}
	for (int i=n; i; i--)
	{
		roz[i]+=(graf[i].empty());
		roz[oj[i]]+=roz[i];
	}
	k=roz[1];
	debug() << imie(k);
	if (k&1)
	{
		printf("NO\n");
		return 0;
	}
	int v;
	v=a;
	while(oj[v]!=1)
		v=oj[v];
	ra=roz[v];
	roz[v]=-1;
	
	v=b;
	while(oj[v]!=1)
		v=oj[v];
	rb=roz[v];
	roz[v]=-1;
	
	v=c;
	while(oj[v]!=1)
		v=oj[v];
	rc=roz[v];
	roz[v]=-1;
	
	v=d;
	while(oj[v]!=1)
		v=oj[v];
	rd=roz[v];
	roz[v]=-1;
	
	for (int i=0; i<graf[1].size(); i++)
		if (roz[graf[1][i]]!=-1)
			wek.push_back(roz[graf[1][i]]);
	
	ple[0]=1;
	for (int i=0; i<wek.size(); i++)
		ple=(ple|(ple<<wek[i]));
	
	plec=(ple<<rc);
	pled=(ple<<rd);
	
	for (int h=0; h<2; h++)
	{
		swap(a, b);
		swap(ra, rb);
		
		for (int i=1; i<=k; i++)
		{
			if (i<=ra || i+rb-1>k || i+rb-1<(k/2+1) || i>(k/2+1))
				continue;
			//if (!(i-a-ra) || !(k-(i+rb-1)))
			//	continue;
			memset(zaj, 0, sizeof(zaj));
			for (int j=1; j<=ra; j++)
				zaj[j]=1;
			for (int j=1; j<=rb; j++)
				zaj[i+j-1]=1;
			int ok=0;
			for (int j=1; j<=k/2 && !ok; j++)
				if (!zaj[j] && !zaj[j+k/2])
					ok=1;
			if (!ok)
				continue;
			if (plec[i-1-ra] || pled[i-1-ra])
			{
				debug() << a << " " << b;
				debug() << ra << " " << rb;
				debug() << i;
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}