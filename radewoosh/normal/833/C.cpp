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

const long long inf=(long long)1000*1000*1000*1000*1000*1007;
const int d=19;

long long a, b;

int ile[d+7];
int dol[d+7];
int gor[d+7];
int pom[d+7];
int pom2[d+7];

int wyn;

int check()
{
	for (int i=0; i<=9; i++)
		pom[i]=ile[i];
	for (int i=0; i<d; i++)
	{
		if (dol[i]==gor[i])
		{
			if (pom[dol[i]])
				pom[dol[i]]--;
			else
				return 0;
			if (i+1==d)
				return 1;
			continue;
		}
		for (int j=dol[i]+1; j<gor[i]; j++)
			if (pom[j])
				return 1;
		
		if (pom[dol[i]])
		{
			int ok=1;
			
			for (int j=0; j<=9; j++)
				pom2[j]=pom[j];
			pom2[dol[i]]--;
			for (int j=i+1; j<d; j++)
			{
				for (int l=dol[j]+1; l<=9; l++)
					if (pom2[l])
						return 1;
				if (!pom2[dol[j]])
				{
					ok=0;
					break;
				}
				pom2[dol[j]]--;
			}
			if (ok)
				return 1;
		}
		if (pom[gor[i]])
		{
			int ok=1;
			
			for (int j=0; j<=9; j++)
				pom2[j]=pom[j];
			pom2[gor[i]]--;
			for (int j=i+1; j<d; j++)
			{
				for (int l=0; l<gor[j]; l++)
					if (pom2[l])
						return 1;
				if (!pom2[gor[j]])
				{
					ok=0;
					break;
				}
				pom2[gor[j]]--;
			}
			if (ok)
				return 1;
		}
		return 0;
	}
}

void licz(int v, int ost)
{
	if (v==d)
	{
		wyn+=check();
		return;
	}
	ile[ost]++;
	licz(v+1, ost);
	ile[ost]--;
	if (ost<9)
		licz(v, ost+1);
}

int main()
{
	scanf("%lld%lld", &a, &b);
	for (int i=0; i<d; i++)
	{
		dol[i]=(a%10);
		a/=10;
		gor[i]=(b%10);
		b/=10;
	}
	reverse(dol, dol+d);
	reverse(gor, gor+d);
	licz(0, 0);
	printf("%d\n", wyn);
	return 0;
}