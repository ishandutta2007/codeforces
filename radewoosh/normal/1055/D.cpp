//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const int nax=3007;

int n;

char najp[nax][nax];
char pot[nax][nax];

int m;
char z[nax];
char na[nax];
vector < pair <string,string> > musz;
int kt[nax];

int kmp[nax];

int sta[nax];

int gdz[nax];

void nope()
{
	printf("NO\n");
	exit(0);
}

int dlu[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", najp[i]+1);
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%s", pot[i]+1);
	}
	for (int i=1; i<=n; i++)
	{
		int d=strlen(najp[i]+1);
		dlu[i]=d;
		int lew=d+1;
		int pra=-1;
		for (int j=1; j<=d; j++)
		{
			if (najp[i][j]!=pot[i][j])
			{
				lew=min(lew, j);
				pra=max(pra, j);
			}
		}
		if (pra!=-1)
		{
			//~ m=pra-lew+1;
			sta[i]=lew;
			string a="";
			string b="";
			for (int j=lew; j<=pra; j++)
				a.push_back(najp[i][j]);
			for (int j=lew; j<=pra; j++)
				b.push_back(pot[i][j]);
			kt[musz.size()]=i;
			musz.push_back({a, b});
			debug() << musz.back();
			//~ znam();
		}
	}
	debug() << musz;
	for (auto i : musz)
		if ((int)i.first.size()!=(int)musz[0].first.size())
			nope();
	m=musz[0].first.size();
	for (int i=1; i<=m; i++)
	{
		z[i]=musz[0].first[i-1];
		na[i]=musz[0].second[i-1];
	}
	int prz=kt[0];
	while(1)
	{
		int chce=0;
		int nie=0;
		for (int i=1; i<=n; i++)
		{
			if (!sta[i])
				continue;
			if (sta[i]+m>dlu[i])
			{
				nie=1;
				continue;
			}
			chce|=(1<<(najp[i][sta[i]+m]-'a'));
		}
		if (nie || __builtin_popcount(chce)>1)
			break;
		char x='a'+__builtin_ctz(chce);
		z[m+1]=x;
		na[m+1]=pot[prz][sta[prz]+m];
		m++;
	}
	while(1)
	{
		int chce=0;
		int nie=0;
		for (int i=1; i<=n; i++)
		{
			if (!sta[i])
				continue;
			if (sta[i]==1)
			{
				nie=1;
				continue;
			}
			chce|=(1<<(najp[i][sta[i]-1]-'a'));
		}
		if (nie || __builtin_popcount(chce)>1)
			break;
		char x='a'+__builtin_ctz(chce);
		for (int i=m+1; i>1; i--)
		{
			z[i]=z[i-1];
			na[i]=na[i-1];
		}
		z[1]=x;
		na[1]=pot[prz][sta[prz]-1];
		for (int i=1; i<=n; i++)
			if (sta[i]>1)
				sta[i]--;
		m++;
	}
	debug() << m << " " << range(z+1, z+1+m) << " " << range(na+1, na+1+m);
	for (int i=2; i<=m; i++)
	{
		int it=kmp[i-1];
		while(it && z[i]!=z[it+1])
			it=kmp[it];
		if (z[i]==z[it+1])
			kmp[i]=it+1;
	}
	debug() << range(kmp+1,kmp+1+m);
	for (int i=1; i<=n; i++)
	{
		int w=0;
		int d=strlen(najp[i]+1);
		for (int j=1; j<=d; j++)
		{
			while(w && najp[i][j]!=z[w+1])
				w=kmp[w];
			if (najp[i][j]==z[w+1])
				w++;
			//~ debug() << i << " " << j << " " << w;
			if (w==m)
			{
				for (int l=1; l<=m; l++)
					najp[i][j-m+l]=na[l];
				break;
			}
		}
	}
	
	for (int i=1; i<=n; i++)
	{
		int d=strlen(najp[i]+1);
		for (int j=1; j<=d; j++)
		{
			if (najp[i][j]!=pot[i][j])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	
	printf("YES\n");
	for (int i=1; i<=m; i++)
		printf("%c", z[i]);
	printf("\n");
	for (int i=1; i<=m; i++)
		printf("%c", na[i]);
	printf("\n");
	return 0;
}