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

int n, m;

vector <int> graf[nax];

int odw;

int num(int i, int j)
{
	if (odw)
		swap(i, j);
	return (i-1)*m+j;
}

int czyzak(int v, int u)
{
	for (int i : graf[v])
		if (i==u)
			return 1;
	return 0;
}

int kol[nax];

void probarand()
{
	shandom_ruffle(kol+1, kol+1+n*m);
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (j<m)
				if (czyzak(kol[num(i, j)], kol[num(i, j+1)]))
					return;
			if (i<n)
				if (czyzak(kol[num(i, j)], kol[num(i+1, j)]))
					return;
		}
	}
	
	printf("YES\n");
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			printf("%d ", kol[num(i, j)]);
		printf("\n");
	}
	exit(0);
}

void probadet()
{
	if (m>n)
	{
		vector <int> wek;
		for (int i=m; i; i--)
		{
			if (i&1)
				wek.push_back(i);
		}
		for (int i=m; i; i--)
		{
			if (!(i&1))
				wek.push_back(i);
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
				kol[num(i, j)]=wek[j-1]+(i-1)*m;
			reverse(wek.begin(), wek.end());
			if (m&1)
				for (int &j : wek)
					j=(m+1-j);
		}
	}
	else
	{
		vector <int> wek;
		for (int i=n; i; i--)
		{
			if (i&1)
				wek.push_back(i);
		}
		for (int i=n; i; i--)
		{
			if (!(i&1))
				wek.push_back(i);
		}
		for (int i=1; i<=m; i++)
		{
			for (int j=1; j<=n; j++)
				kol[num(j, i)]=(wek[j-1]-1)*m+i;
			reverse(wek.begin(), wek.end());
			if (n&1)
				for (int &j : wek)
					j=(n+1-j);
		}
	}
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (j<m)
				if (czyzak(kol[num(i, j)], kol[num(i, j+1)]))
					return;
			if (i<n)
				if (czyzak(kol[num(i, j)], kol[num(i+1, j)]))
					return;
		}
	}
	
	printf("YES\n");
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			printf("%d ", kol[num(i, j)]);
		printf("\n");
	}
	exit(0);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n*m; i++)
		kol[i]=i;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (j<m)
			{
				graf[num(i, j)].push_back(num(i, j+1));
				graf[num(i, j+1)].push_back(num(i, j));
			}
			if (i<n)
			{
				graf[num(i, j)].push_back(num(i+1, j));
				graf[num(i+1, j)].push_back(num(i, j));
			}
		}
	}
	for (int h=0; clock()<=1.2*CLOCKS_PER_SEC; h++)
		probarand();
	probadet();
	printf("NO\n");
	return 0;
}