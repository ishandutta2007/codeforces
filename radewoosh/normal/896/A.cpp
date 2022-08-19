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

const int nax=100*1007;
const long long inf=1007LL*1000LL*1000LL*1000LL*1000LL*1007LL;

long long n, k;

const string start="What are you doing at the end of the world? Are you busy? Will you save us?";
const string przo="What are you doing while sending \"";
const string sro="\"? Are you busy? Will you send \"";
const string kon="\"?";

const int sum=przo.size()+sro.size()+kon.size();

long long dlu[nax];

char daj(long long n, long long k)
{
	if (!n)
		return start[k-1];
	if (k<=(int)przo.size())
		return przo[k-1];
	k-=przo.size();
	if (k<=dlu[n-1])
		return daj(n-1, k);
	k-=dlu[n-1];
	if (k<=(int)sro.size())
		return sro[k-1];
	k-=sro.size();
	if (k<=dlu[n-1])
		return daj(n-1, k);
	k-=dlu[n-1];
	return kon[k-1];
}

void test()
{
	scanf("%lld%lld", &n, &k);
	if (k>dlu[n])
	{
		printf(".");
		return;
	}
	printf("%c", daj(n, k));
}

int main()
{
	dlu[0]=start.size();
	for (int i=1; i<nax; i++)
	{
		dlu[i]=sum+2*dlu[i-1];
		if (dlu[i]>inf)
			dlu[i]=inf;
	}
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	printf("\n");
	return 0;
}