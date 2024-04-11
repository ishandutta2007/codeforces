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

namespace Matching {
    const int N = 600*1007;
    int n, m, nxt[N], fa[N], S[N], Q[N], *Top = Q, pre[N], Vis[N], Tim = 0;
    struct edge {int to, next;}e[2000007]; int head[N], cnt = 1;
    inline void addedge(int x, int y) {e[++cnt] = (edge){y, head[x]}; head[x] = cnt;}
    int getfa(int x) {return (x == fa[x]) ? x : (fa[x] = getfa(fa[x]));}
    inline int lca(int x, int y) {
        for(++Tim, x = getfa(x), y = getfa(y); ; x^= y^= x^= y)
            if(x) {
                if(Vis[x] == Tim) return x;
                Vis[x] = Tim;
                x = getfa(pre[nxt[x]]);
            }
    }
    inline void blossom(int x, int y, int l) {
        while(getfa(x) != l) {
            pre[x] = y;
            if(S[nxt[x]] == 1) S[*Top = nxt[x]] = 0, *Top++;
            if(fa[x] == x) fa[x] = l;
            if(fa[nxt[x]] == nxt[x]) fa[nxt[x]] = l;
            y = nxt[x];
            x = pre[y];
        }
    }
    inline int Match(int x) {
        for(int i = 1; i <= n; ++i) fa[i] = i;
        memset(S, 0xff, sizeof(S));
        S[*(Top = Q) = x] = 0; ++Top;
        for(int *i = Q; i != Top; *i++)
            for(int T = head[*i]; T; T = e[T].next) {
                int y = e[T].to;
                if(S[y] == -1) {
                    pre[y] = *i; S[y] = 1;
                    if(!nxt[y]) {
                        for(int u = y, v = *i, lst; v; u = lst, v = pre[u])
                            lst = nxt[v], nxt[v] = u, nxt[u] = v;
                        return 1;
                    }
                    S[*Top = nxt[y]] = 0; *Top++;
                }
                else if(!S[y] && getfa(y) != getfa(*i)) {
                    int l = lca(y, *i);
                    blossom(y, *i, l);
                    blossom(*i, y, l);
                }
            }
        return 0;
    }
}

vi mygraf[nax];

void superedge(int a, int b)
{
	mygraf[a].push_back(b);
	mygraf[b].push_back(a);
	Matching::addedge(a, b);
	Matching::addedge(b, a);
}

int n;

int tab[nax];

int jest[nax];

int zakaz[nax];

vector<pii> prz;

int wsk;

int dajpus()
{
	while(jest[wsk] || zakaz[wsk])
		wsk--;
	return wsk;
}

void zbierz()
{
	prz.clear();
	int cok=0;
	for (int i=1; i<=n; i++)
		if (tab[i])
			cok=1;
	if (!cok)
	{
		prz.push_back({1, n});
	}
	else
	{
		int a=1;
		int b=n;
		while(!tab[a])
			a++;
		while(!tab[b])
			b--;
		
		if (!jest[tab[a]] && a>1)
			prz.push_back({1, a});
		else if (a>2)
			prz.push_back({1, a-1});
		
		if (!jest[tab[b]] && b<n)
			prz.push_back({b, n});
		else if (b+1<n)
			prz.push_back({b+1, n});
		
		
		for (int i=a; i<b; i++)
		{
			if (!tab[i])
				continue;
			int r=i+1;
			while(!tab[r])
				r++;
			int l=i;
			if (l+1==r)
				continue;
			if (jest[tab[l]])
				l++;
			if (jest[tab[r]])
				r--;
			if (tab[l] && tab[r] && tab[l]==tab[r])
				l++;
			if (l<r)
				prz.push_back({l, r});
		}
	}
}

int proste()
{
	int ret=0;
	for (pii i : prz)
	{
		if (!tab[i.first] && !tab[i.second])
		{
			for (int j=i.first; j<i.second; j+=2)
			{
				int x=dajpus();
				tab[j]=tab[j+1]=x;
				jest[x]=1;
			}
			ret=1;
			continue;
		}
		if (tab[i.first] && !tab[i.second])
		{
			while(i.second>1+i.first)
			{
				int x=dajpus();
				tab[i.second]=x;
				i.second--;
				tab[i.second]=x;
				i.second--;
				jest[x]=1;
			}
			if (i.first+1==i.second)
			{
				tab[i.second]=tab[i.first];
				jest[tab[i.first]]=1;
			}
			ret=1;
			continue;
		}
		if (!tab[i.first] && tab[i.second])
		{
			while(i.second>1+i.first)
			{
				int x=dajpus();
				tab[i.first]=x;
				i.first++;
				tab[i.first]=x;
				i.first++;
				jest[x]=1;
			}
			if (i.first+1==i.second)
			{
				tab[i.first]=tab[i.second];
				jest[tab[i.first]]=1;
			}
			ret=1;
			continue;
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	Matching::n=2*n;
	wsk=n;
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		if (tab[i] && tab[i]==tab[i-1])
			jest[tab[i]]=1;
		zakaz[tab[i]]=1;
	}
	
	while(1)
	{
		zbierz();
		if (!proste())
			break;
	}
	zbierz();
	set<int> fajne;
	int w=n;
	map<pii,pii> tso;
	for (pii i : prz)
	{
		fajne.insert(tab[i.first]);
		fajne.insert(tab[i.second]);
		if ((i.first&1)!=(i.second&1))
		{
			superedge(tab[i.first], tab[i.second]);
			tso[{tab[i.first], tab[i.second]}]=i;
			tso[{tab[i.second], tab[i.first]}]=i;
		}
		else
		{
			w++;
			tso[{w, tab[i.first]}]=i;
			tso[{w, tab[i.second]}]=i;
			superedge(w, tab[i.first]);
			superedge(w, tab[i.second]);
		}
	}
	for (int i : fajne)
		if (!Matching::nxt[i])
			Matching::Match(i);
	for (int i : fajne)
	{
		if (!Matching::nxt[i])
			continue;
		int ile=0;
		for (int j : mygraf[i])
		{
			if (Matching::nxt[j])
				continue;
			Matching::Match(j);
			ile++;
			if (ile==1)
				break;
		}
	}
	//~ for (int i=min(n, 600)+1; i<=w; i++)
		//~ if (!Matching::nxt[i])
			//~ Matching::Match(i);
	
	for (int i : fajne)
	{
		if (!Matching::nxt[i])
			continue;
		int x=Matching::nxt[i];
		//~ debug() << "chce " << i << " " << x;
		if (x>n)
		{
			pii wez=tso[{x, i}];
			int a=wez.first;
			int b=wez.second;
			if (i==tab[a])
			{
				tab[a+1]=tab[a];
				jest[tab[a]]=1;
				for (int j=a+2; j<b; j+=2)
				{
					int nat=dajpus();
					jest[nat]=1;
					tab[j]=tab[j+1]=nat;
				}
			}
			else
			{
				tab[b-1]=tab[b];
				jest[tab[b]]=1;
				for (int j=b-2; j>a; j-=2)
				{
					int nat=dajpus();
					jest[nat]=1;
					tab[j]=tab[j-1]=nat;
				}
			}
		}
		else if (x>i)
		{
			pii wez=tso[{i, x}];
			int a=wez.first;
			int b=wez.second;
			tab[a+1]=tab[a];
			jest[tab[a]]=1;
			tab[b-1]=tab[b];
			jest[tab[b]]=1;
			for (int j=a+2; j+2<b; j+=2)
			{
				int nat=dajpus();
				jest[nat]=1;
				tab[j]=tab[j+1]=nat;
			}
		}
	}
	
	while(1)
	{
		zbierz();
		if (!proste())
			break;
	}
	for (int i=2; i<=n; i++)
		assert(tab[i] || tab[i-1]);
	
	for (int i=1; i<=n; i++)
		printf("%d ", max(1, tab[i]));
	printf("\n");
	//~ set<int> setel;
	//~ for (int i=2; i<=n; i++)
	//~ {
		//~ int a=max(1, tab[i-1]);
		//~ int b=max(1, tab[i]);
		//~ if (a==b)
			//~ setel.insert(a);
	//~ }
	//~ printf("%d\n", (int)setel.size());
	return 0;
}