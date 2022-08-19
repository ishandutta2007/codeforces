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

const int nax=1000*1007;
const long long inf=1000*1000*1000+7;
const int n1=(1<<19);

int n, p, q, r;

struct drz
{
	drz* lew=NULL;
	drz* pra=NULL;
	
	long long fixed=0;
	long long freed=0;
	
	long long czyt(int a, int b, int graa, int grab, long long poz)
	{
		if (a>=graa && b<=grab)
		{
			//debug() << " na " << a << " " << b << " " << imie(fixed) << " " << imie(freed);
			return fixed+freed*(r-poz);
		}
		if (a>grab || b<graa)
		{
			return 0;
		}
		return lew->czyt(a, (a+b)>>1, graa, grab, poz)+pra->czyt((a+b+2)>>1, b, graa, grab, poz);
	}
	drz* fixuj(int a, int b, int cel, long long poz)
	{
		if (a>cel || b<cel)
			return this;
		drz *ret=new drz;
		if (a==b)
		{
			ret->fixed=r-poz;
			ret->freed=0;
			return ret;
		}
		ret->lew=lew->fixuj(a, (a+b)>>1, cel, poz);
		ret->pra=pra->fixuj((a+b+2)>>1, b, cel, poz);
		ret->fixed=ret->lew->fixed+ret->pra->fixed;
		ret->freed=ret->lew->freed+ret->pra->freed;
		return ret;
	}
};

int a[nax];
int b[nax];
int c[nax];

vector <int> weka[nax];
vector <int> wekc[nax];

drz* wys[nax];

long long wyn;

drz* start(int a, int b)
{
	drz* ret=new drz;
	if (a!=b)
	{
		ret->lew=start(a, (a+b)>>1);
		ret->pra=start((a+b+2)>>1, b);
		ret->freed=ret->lew->freed+ret->pra->freed;
	}
	else
	{
		ret->freed=(b<=q);
	}
	return ret;
}

int main()
{
	scanf("%d%d%d%d", &n, &p, &q, &r);
	
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		weka[a[i]].push_back(i);
		wekc[c[i]].push_back(i);
	}
	wys[r+1]=start(1, n1);
	int juz=0;
	for (int i=r; i; i--)
	{
		wys[i]=wys[i+1];
		for (int j : wekc[i])
		{
			while (b[j]>juz)
			{
				juz++;
				wys[i]=wys[i]->fixuj(1, n1, juz, i);
			}
		}
	}
	
	int pra=0;
	int gor=0;
	
	for (int i=p; i; i--)
	{
		for (int j : weka[i])
		{
			pra=max(pra, b[j]);
			gor=max(gor, c[j]);
		}
		//debug() << "dla " << i << " " << imie(pra) << imie(gor);
		wyn+=wys[gor+1]->czyt(1, n1, pra+1, q, gor);
		//debug() << wyn;
	}
	
	printf("%lld\n", wyn);
	return 0;
}