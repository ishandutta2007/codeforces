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

const int nax=500*1007;
const int d=10;

int n;

int nac[d][2];

char wcz[5];
char c;
int x;

int main()
{
	for (int i=0; i<d; i++)
		nac[i][1]=1;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s%d", wcz, &x);
		c=wcz[0];
		if (c=='^')
		{
			for (int i=0; i<d; i++)
			{
				if (x&(1<<i))
				{
					nac[i][0]^=1;
					nac[i][1]^=1;
				}
			}
		}
		if (c=='&')
		{
			for (int i=0; i<d; i++)
			{
				if (!(x&(1<<i)))
				{
					nac[i][0]=0;
					nac[i][1]=0;
				}
			}
		}
		if (c=='|')
		{
			for (int i=0; i<d; i++)
			{
				if (x&(1<<i))
				{
					nac[i][0]=1;
					nac[i][1]=1;
				}
			}
		}
	}
	printf("3\n");
	int x;
	x=0;
	for (int i=0; i<d; i++)
		if (nac[i][0]==1 && nac[i][1]==0)
			x^=(1<<i);
	printf("^ %d\n", x);
	x=0;
	for (int i=0; i<d; i++)
		if (nac[i][0]==1 && nac[i][1]==1)
			x^=(1<<i);
	printf("| %d\n", x);
	x=(1<<d)-1;
	for (int i=0; i<d; i++)
		if (nac[i][0]==0 && nac[i][1]==0)
			x^=(1<<i);
	printf("& %d\n", x);
	return 0;
}