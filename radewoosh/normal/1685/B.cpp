//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
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

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;

int n;
int chce[nax];

char wcz[nax];
int tab[nax];
int ile[nax];

int cie[nax];

void ans(int v)
{
	if (v)
		printf("YES\n");
	else
		printf("NO\n");
}

void test()
{
	for (int i=0; i<4; i++)
	{
		scanf("%d", &chce[i]);
	}
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	ile[0]=ile[1]=0;
	for (int i=1; i<=n; i++)
	{
		tab[i]=wcz[i]-'A';
		ile[tab[i]]++;
	}
	if (ile[0]!=chce[0]+chce[2]+chce[3] || ile[1]!=chce[1]+chce[2]+chce[3])
	{
		ans(0);
		return;
	}
	for (int i=0; i<=n; i++)
		cie[i]=0;
	cie[0]=cie[n]=1;
	for (int i=1; i<n; i++)
		if (tab[i]==tab[i+1])
			cie[i]=1;
	int v=0;
	int wsp=0;
	vi pie, dru;
	while(v<n)
	{
		int u=v+1;
		while(!cie[u])
			u++;
		int d=u-v;
		if (d&1)
		{
			wsp+=d/2;
		}
		else
		{
			if (tab[v+1]==0)
				pie.push_back(d/2-1);
			else
				dru.push_back(d/2-1);
			wsp+=d/2-1;
		}
		v=u;
	}
	sort(pie.begin(), pie.end());
	sort(dru.begin(), dru.end());
	reverse(pie.begin(), pie.end());
	reverse(dru.begin(), dru.end());
	int a=chce[2];
	int b=chce[3];
	//~ debug() << a << " " << b << " " << wsp << " " << pie << " " << dru;
	while(a>0 || b>0)
	{
		if (!pie.empty() && a>pie.back())
		{
			int x=pie.back();
			wsp-=x;
			a-=pie.back()+1;
			pie.pop_back();
			continue;
		}
		if (!dru.empty() && b>dru.back())
		{
			int x=dru.back();
			wsp-=x;
			b-=dru.back()+1;
			dru.pop_back();
			continue;
		}
		if (a>0 && wsp>0)
		{
			a--;
			wsp--;
			continue;
		}
		if (b>0 && wsp>0)
		{
			b--;
			wsp--;
			continue;
		}
		ans(0);
		return;
	}
	ans(1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}