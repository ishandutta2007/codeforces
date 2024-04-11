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
const int nax=1000*1007;

const ll mod1=1000*1000*1000+7;
const ll mod2=1000*1000*1000+9;
const ll H=100003;

pll doloz(pll hasz, char znak)
{
	return {(hasz.first*H+znak)%mod1, (hasz.second*H+znak)%mod2};
}

int n;

char doj[nax];
vector <pii> graf[nax];

int l;
int pre[nax];
int post[nax];

int odl[nax];

vi jump[nax];

void dfs1(int v, int oj=0)
{
	l++;
	pre[v]=l;
	jump[v].push_back(oj);
	while(jump[v].back())
	{
		int a=jump[v].back();
		int b=min(jump[v].size(), jump[a].size())-1;
		jump[v].push_back(jump[a][b]);
	}
	
	for (pii i : graf[v])
	{
		if (i.first!=oj)
		{
			odl[i.first]=odl[v]+1;
			doj[i.first]=i.second;
			dfs1(i.first, v);
			
		}
	}
	l++;
	post[v]=l;
}

int przo(int a, int b)
{
	return (pre[a]<=pre[b] && post[a]>=post[b]);
}

int lca(int a, int b)
{
	if (przo(a, b))
		return a;
	for (int i=20; i>=0; i--)
		if (i<(int)jump[a].size() && jump[a][i] && !przo(jump[a][i], b))
			a=jump[a][i];
	return jump[a][0];
}

int skocz(int v, int u)
{
	for (int i=0; (1<<i)<=u; i++)
		if (u&(1<<i))
			v=jump[v][i];
	return v;
}

int drz[nax];

void pisz(int a, int b, int w)
{
	for (int i=b; i; i-=(i&(-i)))
		drz[i]+=w;
	for (int i=a-1; i; i-=(i&(-i)))
		drz[i]-=w;
}

int czyt(int v)
{
	int ret=0;
	for (int i=v; i<=2*n; i+=(i&(-i)))
		ret+=drz[i];
	return ret;
}

int kmp(string a, string b)
{
	string s="#"+a+"$"+b;
	vi kmp(s.size(), 0);
	for (int i=2; i<(int)s.size(); i++)
	{
		int it=kmp[i-1];
		while(it && s[i]!=s[it+1])
			it=kmp[it];
		if (s[i]==s[it+1])
			kmp[i]=it+1;
	}
	int ret=0;
	for (int i : kmp)
		if (i==(int)a.size())
			ret++;
	return ret;
}

int q;
pii zap[nax];
char wcz[nax];

int wyn[nax];

unordered_map <ll,vector <pii> > gro;
unordered_map <ll,vi> ter;

pll pus;

pll trz[nax];

ll kwi(pll v)
{
	return v.first*mod2+v.second;
}

void zrob(ll kto, vi gdz)
{
	for (int i : gdz)
		pisz(pre[i], post[i], 1);
	for (pii i : gro[kto])
	{
		int znak=i.second/abs(i.second);
		int daj=abs(i.second);
		wyn[daj]+=znak*czyt(pre[i.first]);
	}
	for (int i : gdz)
		pisz(pre[i], post[i], -1);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		char c;
		scanf("%d%d %c", &a, &b, &c);
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
	}
	odl[1]=1;
	dfs1(1);
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		scanf("%d%d%s", &zap[i].first, &zap[i].second, wcz+1);
		int r=strlen(wcz+1);
		string wla="";
		for (int j=1; j<=r; j++)
			wla+=wcz[j];
		pll raz=pus;
		pll dwa=pus;
		for (int j=1; j<=r; j++)
			raz=doloz(raz, wcz[j]);
		for (int j=r; j; j--)
			dwa=doloz(dwa, wcz[j]);
		int w=lca(zap[i].first, zap[i].second);
		//~ debug() << raz << " " << dwa;
		int s1=zap[i].first;
		int s2=zap[i].second;
		int pom=odl[zap[i].first]-odl[w];
		if (pom>=r)
		{
			gro[kwi(raz)].push_back({zap[i].first, i});
			s1=skocz(zap[i].first, pom-r+1);
			gro[kwi(raz)].push_back({skocz(zap[i].first, pom-r+1), -i});
		}
		pom=odl[zap[i].second]-odl[w];
		if (pom>=r)
		{
			gro[kwi(dwa)].push_back({zap[i].second, i});
			s2=skocz(zap[i].second, pom-r+1);
			gro[kwi(dwa)].push_back({skocz(zap[i].second, pom-r+1), -i});
		}
		string aa="", bb="";
		while(s1!=w)
		{
			aa+=doj[s1];
			s1=jump[s1][0];
		}
		while(s2!=w)
		{
			bb+=doj[s2];
			s2=jump[s2][0];
		}
		reverse(bb.begin(), bb.end());
		aa+=bb;
		wyn[i]=kmp(wla, aa);
	}
	for (int h=1; h<=100; h++)
	{
		ter.clear();
		for (int i=1; i<=n; i++)
		{
			if (odl[i]>h)
			{
				trz[i]=doloz(trz[i], doj[skocz(i, h-1)]);
				if (gro.count(kwi(trz[i])))
					ter[kwi(trz[i])].push_back(i);
			}
		}
		for (auto i : ter)
			zrob(i.first, i.second);
	}
	
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
	return 0;
}