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
const int kax=17;
const int inf=1007*1007*1007;

int n, k;

struct spo
{
	int dol[kax];
	int gor[kax];
	int licz=0;
	spo()
	{
		for (int i=1; i<=k; i++)
			dol[i]=inf;
	}
	void wczyt()
	{
		for (int i=1; i<=k; i++)
		{
			scanf("%d", &dol[i]);
			gor[i]=dol[i];
		}
		licz=1;
	}
};

spo merge(spo &a, spo &b)
{
	spo ret=spo();
	ret.licz=a.licz+b.licz;
	for (int i=1; i<=k; i++)
	{
		ret.gor[i]=max(a.gor[i], b.gor[i]);
		ret.dol[i]=min(a.dol[i], b.dol[i]);
	}
	return ret;
}

int ist[nax];
/*int oj[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int v, int u)
{
	v=fin(v);
	u=fin(u);
	oj[v]=u;
}*/

spo tab[nax];

int m;

priority_queue < pair <int,int> > gors[kax];

void przewin(priority_queue < pair <int,int> > &kol)
{
	while((int)kol.size()>0)
	{
		auto x=kol.top();
		kol.pop();
		if (!ist[x.second])
			continue;
		kol.push(x);
		break;
	}
	while((int)kol.size()>1)
	{
		auto x=kol.top();
		kol.pop();
		auto y=kol.top();
		kol.pop();
		if (!ist[x.second])
		{
			kol.push(y);
			continue;
		}
		if (!ist[y.second])
		{
			kol.push(x);
			continue;
		}
		kol.push(x);
		kol.push(y);
		break;
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	m=n;
	for (int i=1; i<=n; i++)
		tab[i].wczyt();
	for (int i=1; i<=n; i++)
	{
		ist[i]=1;
		for (int j=1; j<=k; j++)
			gors[j].push({tab[i].gor[j], i});
		int czy=1;
		while(czy)
		{
			czy=0;
			for (int j=1; j<=k && !czy; j++)
			{
				przewin(gors[j]);
				if (gors[j].size()==1)
					continue;
				auto x=gors[j].top();
				gors[j].pop();
				auto y=gors[j].top();
				gors[j].pop();
				if (tab[y.second].gor[j]>tab[x.second].dol[j])
				{
					debug() << "merge " << x << " " << y;
					m++;
					ist[y.second]=0;
					ist[x.second]=0;
					ist[m]=1;
					tab[m]=merge(tab[x.second], tab[y.second]);
					for (int l=1; l<=k; l++)
						gors[l].push({tab[m].gor[l], m});
					czy=1;
				}
				else
				{
					gors[j].push(x);
					gors[j].push(y);
				}
			}
			przewin(gors[1]);
			for (int j=2; j<=k && !czy; j++)
			{
				przewin(gors[j]);
				debug() << " pacze na " << j << " " << gors[1].top().second << "  " << gors[j].top().second;
				if (gors[1].top().second!=gors[j].top().second)
				{
					int x=gors[1].top().second;
					int y=gors[j].top().second;
					debug() << "merge " << x << " " << y;
					m++;
					ist[x]=0;
					ist[y]=0;
					ist[m]=1;
					tab[m]=merge(tab[x], tab[y]);
					for (int l=1; l<=k; l++)
						gors[l].push({tab[m].gor[l], m});
					czy=1;
				}
			}
		}
		printf("%d\n", tab[gors[1].top().second].licz);
	}
	return 0;
}