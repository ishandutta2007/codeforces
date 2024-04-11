#include <bits/stdc++.h>
using namespace std;

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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

const int nax=107*1007;
const int n1ax=300*1007;

int n;
int k;
vector <int> graf[nax];

int l;
int pre[nax];
int post[nax];
int roz[nax];

int wyn[nax];

int n1;
multiset <int> drzewo[n1ax];

int potenga(int v)
{
	for (int i=1; 1; i<<=1)
		if (i>v)
			return i;
}

void dorzuc(int v, int w)
{
	v+=n1-1;
	while(v)
	{
		drzewo[v].insert(w);
		v>>=1;
	}
}

void usun(int v, int w)
{
	v+=n1-1;
	while(v)
	{
		drzewo[v].erase(drzewo[v].find(w));
		v>>=1;
	}
}

int finded;

multiset <int>::iterator it;

int ost(multiset <int> &setel)
{
	it=setel.end();
	it--;
	return (*it);
}

void spytaj(int v, int a, int b, int graa, int grab, int wa, int wb)
{
	if (finded || wa>wb || drzewo[v].empty() || (*drzewo[v].begin())>wb || ost(drzewo[v])<wa)
		return;
	if (a>=graa && b<=grab)
	{
		it=drzewo[v].lower_bound(wa);
		if (it!=drzewo[v].end() && (*it)<=wb)
			finded=1;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	spytaj((v<<1), a, (a+b)>>1, graa, grab, wa, wb);
	spytaj((v<<1)^1, (a+b+2)>>1, b, graa, grab, wa, wb);
}

void dfs1(int v)
{
	l++;
	pre[v]=l;
	roz[v]=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		dfs1(graf[v][i]);
		roz[v]+=roz[graf[v][i]];
	}
	post[v]=l;
}

multiset <int> multi;

int czy_mul(int a, int b)
{
	if (a>b)
		return 0;
	return (multi.lower_bound(a)!=multi.upper_bound(b));
}

void dfs2(int v)
{
	vector < pair <int,int> > wek;
	for (int i=0; i<graf[v].size(); i++)
		wek.push_back({roz[graf[v][i]], graf[v][i]});
	if (v!=k)
		wek.push_back({n-roz[v], 0});
		
	if (wek.size()==1)
	{
		wyn[v]=n-1;
	}
	else
	{
		sort(wek.begin(), wek.end());
		reverse(wek.begin(), wek.end());
		int bsa=wek[1].first;
		int bsb=wek[0].first;
		int bss;
		
		int x=wek[0].second;
		
		if (x)//dol
		{
			while(bsa<bsb)
			{
				bss=(bsa+bsb)>>1;
				finded=0;
				spytaj(1, 1, n1, pre[x]+1, post[x], wek[0].first-bss, bss-wek.back().first);
				if (finded)
					bsb=bss;
				else
					bsa=bss+1;
			}
		}
		else//gora
		{
			while(bsa<bsb)
			{
				bss=(bsa+bsb)>>1;
				finded=0;
				if (czy_mul(wek[0].first-bss+roz[v], bss-wek.back().first+roz[v]))
					finded=1;
				spytaj(1, 1, n1, 2, pre[v]-1, wek[0].first-bss, bss-wek.back().first);
				spytaj(1, 1, n1, post[v]+1, n, wek[0].first-bss, bss-wek.back().first);
				if (finded)
					bsb=bss;
				else
					bsa=bss+1;
			}
		}
		wyn[v]=bsb;
		
	}
	
	
	usun(pre[v], roz[v]);
	if (v!=k)
		multi.insert(roz[v]);
	
	for (int i=0; i<graf[v].size(); i++)
		dfs2(graf[v][i]);
		
	dorzuc(pre[v], roz[v]);
	if (v!=k)
		multi.erase(multi.find(roz[v]));
}

int main()
{
	scanf("%d", &n);
	if (n==1)
	{
		printf("0\n");
		return 0;
	}
	for (int i=1; i<=n; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		if (p1)
			graf[p1].push_back(p2);
		else
			k=p2;
	}
	n1=potenga(n);
	dfs1(k);
	for (int i=1; i<=n; i++)
		dorzuc(pre[i], roz[i]);
		
	dfs2(k);
	
	for (int i=1; i<=n; i++)
		printf("%d\n", wyn[i]);
	return 0;
}