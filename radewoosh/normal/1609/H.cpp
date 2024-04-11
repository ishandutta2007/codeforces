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
const int nax=1007;
const ll inf=1007LL*1007LL*1007LL*1007LL*1007LL*1007LL;

int n, k, q;

ll poz[nax];

ll ins[nax][nax];

int kto[nax];
ll kied[nax];
ll wyn[nax];

vector<pair<ll,int>>pos;

vector<pair<int,ll>>pomruch;
vi czyok;

int czyoddal(ll lew, ll pra)
{
	if (lew<=0 && pra>=0 && (lew || pra))
		return 1;
	return 0;
}

int czylaczyc(ll lew, ll pra)
{
	if (lew>0)
		return 1;
	if (pra<0)
		return 1;
	if (!lew && !pra)
		return 1;
	return 0;
}

int wykonaj(int v)
{
	int ret=0;
	pomruch.clear();
	for (int i=1; i<=n; i++)
	{
		int ja=1;
		ll mam=ins[i][v];
		while(!pomruch.empty() && czylaczyc(pomruch.back().second, mam) && poz[i-ja]+1==poz[i-ja+1])
		{
			ja+=pomruch.back().first;
			mam+=pomruch.back().second;
			pomruch.pop_back();
		}
		pomruch.push_back({ja, mam});
	}
	czyok.clear();
	czyok.resize(pomruch.size(), 1);
	//~ debug() << pomruch;
	int ost=pomruch[0].first;
	for (int i=1; i<(int)pomruch.size(); i++)
	{
		int tu=pomruch[i].first;
		if (pomruch[i].second<0 && pomruch[i-1].second>0 && poz[ost]+2==poz[ost+1])
		{
			ost+=tu;
			if (pomruch[i-1].second>-pomruch[i].second)
				czyok[i]=0;
			else
				czyok[i-1]=0;
			ret=1;
			continue;
		}
		ost+=tu;
	}
	//~ debug() << czyok;
	ost=0;
	for (int i=0; i<(int)pomruch.size(); i++)
	{
		int tu=pomruch[i].first;
		if (!pomruch[i].second || !czyok[i])
		{
			ost+=tu;
			continue;
		}
		//~ debug() << i << " " << ost << " " << pomruch[i];
		if (pomruch[i].second>0)
		{
			while(tu--)
			{
				ost++;
				poz[ost]++;
			}
		}
		else
		{
			while(tu--)
			{
				ost++;
				poz[ost]--;
			}
		}
	}
	return ret;
}

ll mom;
int wsk;

ll byl[nax][nax];
ll szi[nax];

void licz_fast(ll moge)
{
	ll ret=moge-2;
	for (int i=0; i<2*k; i++)
	{
		for (int j=1; j<=n; j++)
			byl[i][j]=poz[j];
		wykonaj(i%k);
	}
	for (int j=1; j<=n; j++)
		byl[2*k][j]=poz[j];
	int ok=1;
	for (int j=1; j<=n; j++)
		szi[j]=byl[k][j]-byl[0][j];
	for (int i=0; i<=k; i++)
		for (int j=1; j<=n; j++)
			if (byl[i][j]+szi[j]!=byl[k+i][j])
				ok=0;
	mom+=2*k;
	if (!ok)
		return;
	for (int i=1; i<n; i++)
	{
		ll odl=inf;
		for (int j=0; j<=k; j++)
			odl=min(odl, byl[j][i+1]-byl[j][i]);
		ll doch=szi[i]-szi[i+1];
		if (doch>0)
			ret=min(ret, odl/doch-2);
	}
	ret=max(ret, 0LL);
	mom+=ret*k;
	for (int i=1; i<=n; i++)
		poz[i]+=szi[i]*ret;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%lld", &poz[i]);
	for (int i=1; i<=n; i++)
		for (int j=0; j<k; j++)
			scanf("%lld", &ins[i][j]);
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		scanf("%d%lld", &kto[i], &kied[i]);
		pos.push_back({kied[i], i});
	}
	sort(pos.begin(), pos.end());
	//~ debug() << wsk << " " << pos;
	while(wsk<(int)pos.size())
	{
		//~ debug() << imie(mom) << range(poz+1, poz+1+n);
		if (mom==pos[wsk].first)
		{
			int v=pos[wsk].second;
			wyn[v]=poz[kto[v]];
			wsk++;
			continue;
		}
		if ((mom%k) || mom+3*k>=pos[wsk].first)
		{
			wykonaj(mom%k);
			mom++;
			continue;
		}
		ll moge=(pos[wsk].first-mom)/k;
		licz_fast(moge);
	}
	
	for (int i=1; i<=q; i++)
		printf("%lld\n", wyn[i]);
	return 0;
}