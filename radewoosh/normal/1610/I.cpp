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

vi graf[nax];

int minidol[nax];
int minigor[nax];
int dol[nax];
int gor[nax];

int ojc[nax];

void dfs1(int v, int oj)
{
	minidol[v]=v;
	for (int &i : graf[v])
	{
		if (i!=oj)
			continue;
		swap(i, graf[v].back());
		graf[v].pop_back();
		break;
	}
	ojc[v]=oj;
	for (int i : graf[v])
	{
		dfs1(i, v);
		dol[v]^=(dol[i]+1);
		minidol[v]=min(minidol[v], minidol[i]);
	}
}

int out[nax];

void dfs2(int v)
{
	int wsz=0;
	if (v!=1)
		wsz^=(gor[v]+1);
	for (int i : graf[v])
		wsz^=(dol[i]+1);
	for (int i : graf[v])
	{
		gor[i]=wsz^(dol[i]+1);
	}
	vector<pii> sor;
	sor.push_back({minigor[v], ojc[v]});
	sor.push_back({v, v});
	for (int i : graf[v])
		sor.push_back({minidol[i], i});
	sort(sor.begin(), sor.end());
	for (int i : graf[v])
	{
		for (pii j : sor)
		{
			if (i!=j.second)
			{
				minigor[i]=j.first;
				break;
			}
		}
	}
	for (int i : graf[v])
	{
		dfs2(i);
	}
}

int pre[nax];

void cons(int oa, int ob, int xa, int xb)
{
	if (oa>ob)
	{
		swap(oa, ob);
		swap(xa, xb);
	}
	pre[oa]^=xb+1;
	pre[ob]^=xb+1;
	pre[ob]^=1;
	//~ debug() << oa << " " << ob << " " << xa << " " << xb;
}

void dfs3(int v)
{
	for (int i : graf[v])
	{
		cons(out[i], out[v], dol[i], gor[i]);
		dfs3(i);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=0; i<=n; i++)
		minidol[i]=minigor[i]=n+1;
	dfs1(1, 0);
	dfs2(1);
	//~ for (int i=1; i<=n; i++)
		//~ debug() << i << " " << dol[i] << " " << gor[i] << "   " << minigor[i] << " " << minidol[i];
	for (int i=1; i<=n; i++)
	{
		out[i]=i;
		vi kied;
		for (int j : graf[i])
			kied.push_back(minidol[j]);
		if (i!=1)
			kied.push_back(minigor[i]);
		sort(kied.begin(), kied.end());
		if ((int)kied.size()>=2)
			out[i]=min(out[i], kied[1]);
	}
	//~ for (int i=1; i<=n; i++)
		//~ debug() << i << " " << out[i];
	dfs3(1);
	for (int i=1; i<=n; i++)
		pre[i]^=pre[i-1];
	//~ debug() << range(pre+1, pre+1+n);
	for (int i=1; i<=n; i++)
	{
		if (pre[i])
			printf("1");
		else
			printf("2");
	}
	printf("\n");
	return 0;
}