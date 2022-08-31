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

int n;

long long k, m;

long long pocz;
long long wyn;

int tab[nax];

vector < pair <int,long long> > wek;

int l, r;

int main()
{
	scanf("%d%lld%lld", &n, &k, &m);
	pocz=n*m;
	
	if (m<=3)
	{
		vector <int> pam;
		for (int i=1; i<=n; i++)
		{
			int x;
			scanf("%d", &x);
			pam.push_back(x);
		}
		while(m--)
		{
			for (int i=1; i<=n; i++)
			{
				int x;
				x=pam[i-1];
				if (wek.empty() || wek.back().first!=x)
					wek.push_back({x, 0});
				wek.back().second++;
				if (wek.back().second==k)
				{
					wyn+=k;
					wek.pop_back();
				}
			}
		}
		long long trz=0;
		for (auto i : wek)
			trz+=i.second;
		printf("%lld\n", trz);
		return 0;
	}

	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		if (wek.empty() || wek.back().first!=x)
			wek.push_back({x, 0});
		wek.back().second++;
		if (wek.back().second==k)
		{
			wyn+=k*m;
			wek.pop_back();
		}
	}
	if (wek.empty())
	{
		printf("0\n");
		return 0;
	}
	n=0;
	for (auto i : wek)
	{
		for (int j=0; j<i.second; j++)
		{
			n++;
			tab[n]=i.first;
		}
	}
	l=1;
	r=n;
	
	while(r-l+1>k)
	{
		int i1=0;
		int i2=0;
		while(i1+i2<k && tab[r-i1]==tab[r])
			i1++;
		while(i1+i2<k && tab[l+i2]==tab[r])
			i2++;
		if (i1+i2==k)
		{
			r-=i1;
			l+=i2;
			wyn+=(m-1)*k;
			continue;
		}
		break;
	}
	
	int takie=1;
	
	for (int i=l; i<=r; i++)
		if (tab[i]!=tab[l])
			takie=0;
	
	if (takie)
	{
		long long dorz=(m-2)*(r-l+1);
		wek.clear();
		for (int i=1; i<=r; i++)
		{
			int x=tab[i];
			if (wek.empty() || wek.back().first!=x)
				wek.push_back({x, 0});
			wek.back().second++;
			if (wek.back().second==k)
			{
				wyn+=k;
				wek.pop_back();
			}
		}
		if (!wek.empty() && tab[l]==wek.back().first)
		{
			wek.back().second+=dorz;
		}
		else
		{
			wek.push_back({tab[l], dorz});
		}
		wyn+=k*(wek.back().second/k);
		wek.back().second%=k;
		if (!wek.back().second)
			wek.pop_back();
		for (int i=l; i<=n; i++)
		{
			int x=tab[i];
			if (wek.empty() || wek.back().first!=x)
				wek.push_back({x, 0});
			wek.back().second++;
			if (wek.back().second==k)
			{
				wyn+=k;
				wek.pop_back();
			}
		}
	}
	
	
	printf("%lld\n", pocz-wyn);
	return 0;
}