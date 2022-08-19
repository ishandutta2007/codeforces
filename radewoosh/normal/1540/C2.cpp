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
const int nax=107;
const int vax=107*107;
const ll mod=1000*1000*1000+7;
const ll o2=(mod+1)/2;

int n;

int c[nax];
int b[nax];

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

ll dps[nax][vax];
ll dpn[nax][vax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int odej[nax];
int dol[nax];

int miesci(int li, int mi)
{
	int x=li/mi;
	if (x*mi>li)
		x--;
	if ((x+1)*mi<=li)
		x++;
	return x;
}

ll sum[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i=1; i<n; i++)
	{
		scanf("%d", &b[i]);
	}
	dpn[0][0]=1;
	for (int i=2; i<=n; i++)
	{
		odej[i]=odej[i-1];
		for (int j=1; j<i; j++)
			odej[i]+=b[j];
	}
	for (int i=1; i<=n; i++)
		dol[i]=miesci(-odej[i], i);
	dol[0]=vax;
	for (int i=1; i<=n; i++)
	{
		//~ debug() << i;
		for (int j=0; j<nax; j++)
		{
			for (int l=0; l<vax; l++)
			{
				dps[j][l]=dpn[j][l];
				dpn[j][l]=0;
			}
		}
		for (int j=0; j<nax; j++)
		{
			ll s=0;
			for (int l=0; l<vax; l++)
			{
				s+=dps[j][l];
				if (l>c[i])
					s-=dps[j][l-c[i]-1];
				if (s<0)
					s+=mod;
				dpn[j][l]=s;
			}
		}
		for (int j=0; j<nax; j++)
		{
			for (int l=0; l<vax; l++)
			{
				dps[j][l]=dpn[j][l];
				dpn[j][l]=0;
			}
		}
		//~ debug() << "przed";
		for (int j=0; j<nax; j++)
		{
			for (int l=0; l<vax; l++)
			{
				if (!dps[j][l])
					continue;
				int ogr=min(dol[i-1]+j, miesci(l-odej[i], i));
				//~ if (dps[j][l])
				//~ {
					//~ debug()  << j << " " << nax << " " << ogr-dol[i];
				//~ }
				//~ assert(j<nax);
				//~ debug() << j << " " << nax <<"    " << ogr << " " << dol[i];
				//~ debug()  << j << " " << ogr-dol[i];
				dod(dpn[ogr-dol[i]][l], dps[j][l]);
			}
		}
		//~ debug() << "kon";
	}
	//~ ll wyn=0;
	//~ for (int i=0; i<vax; i++)
		//~ dod(wyn, dp[n][i]);
	//~ printf("%lld\n", wyn);
	for (int i=0; i<nax; i++)
		for (int j=0; j<vax; j++)
			dod(sum[i], dpn[i][j]);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int lim;
		scanf("%d", &lim);
		ll wyn=0;
		for (int i=0; i<nax; i++)
			if (dol[n]+i>=lim)
				wyn+=sum[i];
		
		wyn%=mod;
		printf("%lld\n", wyn);
	}
	return 0;
}