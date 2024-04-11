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

const int nax=1007;
const int d=250;

double tab[nax];

int main()
{
	//srand(time(0));
	//default_random_engine generator;
	//poisson_distribution<int> distribution(20.0);
	int t;
	scanf("%d", &t);
	//int li=20;
	while(t--)
	{
		double s=0.0;
		double o=0.0;
		for (int i=1; i<=d; i++)
		{
			//tab[i]=(rand()%li)+1;
			//tab[i]=distribution(generator);
			scanf("%lf", &tab[i]);
			s+=tab[i];
		}
		s/=d;
		for (int i=1; i<=d; i++)
			o+=(s-tab[i])*(s-tab[i]);
		o/=d;
		o=sqrt(o);
		//if ((o*2+2>s))
		//	debug() << "CHUJ";
		//debug() << o << " " << s << " bo " << li;
		//li++;
		double raz=s/2.0;
		double dwa=sqrt(s);
		if (abs(raz-o)<abs(dwa-o))
			printf("uniform\n");
		else
			printf("poisson\n");
	}
	return 0;
}