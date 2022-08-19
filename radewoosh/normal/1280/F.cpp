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
const int nax=107;

int n;
string in[nax][nax];

string wyn;
string wynp, wyns;
vector <string> shortcut;

string nalew, zlew, napra, zpra;

int m;
vi tab;
int idea[nax];

int gdzpow[nax];

int nor[nax][nax];

string odw(string s)
{
	reverse(s.begin(), s.end());
	for (char &i : s)
	{
		if (i=='l' || i=='r')
			i^=('l'^'r');
		else
			i^=('u'^'d');
	}
	return s;
}

vi zloz(vi a, vi b)
{
	vi ret(m+1);
	for (int i=1; i<=m; i++)
		ret[i]=b[a[i]];
	return ret;
}

vi rusz(vi a, vi b)
{
	vi ret(m+1);
	for (int i=1; i<=m; i++)
		ret[b[i]]=a[i];
	return ret;
}

vi odw(vi v)
{
	vi ret(m+1);
	for (int i=1; i<=m; i++)
		ret[v[i]]=i;
	return ret;
}

vi iden;
vi nalewp, zlewp, naprap, zprap;

vector <vi> pods;

char start;

char szukaj(vi wek)
{
	start++;
	vector <pair<string,vi> > now, sta;
	now.push_back({"", iden});
	now[0].first+=start;
	now[0].first+=" ";
	while(1)
	{
		sta=now;
		now.clear();
		for (auto i : sta)
		{
			for (int j=0; j<4; j++)
			{
				char c='A'+j;
				string op=i.first;
				op+=c;
				vi ter=zloz(i.second, pods[j]);
				now.push_back({op, ter});
			}
		}
		for (auto i : now)
		{
			if (i.second==wek)
			{
				pods.push_back(wek);
				shortcut.push_back(i.first);
				return start;
			}
		}
	}
}

void algo()
{
	vi pier=iden;
	swap(pier[1], pier[2]);
	swap(pier[2], pier[3]);
	//~ szukaj(pier);
	//~ debug() << shortcut.back();
	
	vi poza=iden;
	for (int i=3; i<m; i++)
		swap(poza[i], poza[i+1]);
	//~ szukaj(poza);
	//~ debug() << shortcut.back();
	
	shortcut.push_back("E BCBDBCAADA");
	shortcut.push_back("F BBDACADA");
	pods.push_back(pier);
	pods.push_back(poza);
	
	while(!(tab[1]<=2 && tab[2]<=2))
	{
		if (tab[3]<=2)
		{
			wyn+='E';
			tab=rusz(tab, pods[4]);
		}
		else
		{
			wyn+='F';
			tab=rusz(tab, pods[5]);
		}
	}
	while(1)
	{
		int pos=1;
		for (int i=1; i<=m; i++)
			if (tab[i]!=i)
				pos=0;
		if (pos)
			break;
		int v=m;
		while(tab[v]==v)
			v--;
		vi cyk;
		int u=v;
		while(u!=v || cyk.empty())
		{
			cyk.push_back(v);
			v=tab[v];
		}
		cyk.push_back(1);
		int gm=m;
		int kt=1;
		for (int i : cyk)
		{
			while(tab[3]!=i)
			{
				if (i==1 && tab[3]==2)
					break;
				gm++;
				if (gm==m+1)
					gm=3;
				wyn+='F';
				tab=rusz(tab, pods[5]);
			}
			wyn+='E';
			tab=rusz(tab, pods[4]);
			if (kt)
			{
				wyn+='E';
				tab=rusz(tab, pods[4]);
			}
			kt^=1;
		}
		while(gm!=m)
		{
			gm++;
			if (gm==m+1)
				gm=3;
			wyn+='F';
			tab=rusz(tab, pods[5]);
		}
	}
}

void test()
{
	cin >> n;
	for (int j=1; j<=2; j++)
		for (int l=1; l<=2*n+1; l++)
			cin >> in[j][l];
	wyn="";
	wynp=wyns="";
	shortcut.clear();
	int g1=0;
	int g2=0;
	for (int i=1; i<=2; i++)
	{
		for (int j=1; j<=2*n+1; j++)
		{
			if (in[i][j]=="E")
			{
				g1=i;
				g2=j;
			}
		}
	}
	while(g2<n+1)
	{
		wynp+='r';
		swap(in[g1][g2], in[g1][g2+1]);
		g2++;
	}
	while(g2>n+1)
	{
		wynp+='l';
		swap(in[g1][g2], in[g1][g2-1]);
		g2--;
	}
	if (g1==1)
	{
		wynp+='d';
		swap(in[2][g2], in[1][g2]);
		g1++;
	}
	for (int i=1; i<=n; i++)
		wyns+='r';
	int num=0;
	for (int i=1; i<=2; i++)
	{
		for (int j=1; j<=2*n+1; j++)
		{
			if (i==2 && j==n+1)
				continue;
			num++;
			nor[i][j]=num;
		}
	}
	m=0;
	tab.resize(4*n+2);
	for (int i=n; i; i--)
	{
		m++;
		tab[m]=stoi(in[2][i]);
		idea[m]=nor[2][i];
	}
	for (int i=1; i<=2*n+1; i++)
	{
		m++;
		tab[m]=stoi(in[1][i]);
		idea[m]=nor[1][i];
	}
	for (int i=2*n+1; i>n+1; i--)
	{
		m++;
		tab[m]=stoi(in[2][i]);
		idea[m]=nor[2][i];
	}
	for (int i=1; i<=m; i++)
		gdzpow[idea[i]]=i;
	for (int i=1; i<=m; i++)
		tab[i]=gdzpow[tab[i]];
	debug() << tab;
	int parz=0;
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<i; j++)
			if (tab[j]>tab[i])
				parz^=1;
	}
	if (parz)
	{
		cout << "SURGERY FAILED\n";
		return;
	}
	nalew=zlew=napra=zpra="";
	nalew+='u';
	for (int i=1; i<=n; i++)
		nalew+='l';
	nalew+='d';
	for (int i=1; i<=n; i++)
		nalew+='r';
	zlew=odw(nalew);
	
	napra+='u';
	for (int i=1; i<=n; i++)
		napra+='r';
	napra+='d';
	for (int i=1; i<=n; i++)
		napra+='l';
	zpra=odw(napra);
	
	nalew="A "+nalew;
	zlew="B "+zlew;
	napra="C "+napra;
	zpra="D "+zpra;
	nalewp.resize(m+1);
	iota(nalewp.begin(), nalewp.end(), 0);
	iden=naprap=nalewp;
	for (int i=(m+1)/2; i>1; i--)
		swap(nalewp[i], nalewp[i-1]);
	for (int i=(m+1)/2; i<m; i++)
		swap(naprap[i], naprap[i+1]);
	zlewp=odw(nalewp);
	zprap=odw(naprap);
	swap(nalewp, zlewp);
	swap(naprap, zprap);
	shortcut={nalew, zlew, napra, zpra};
	
	start='D';
	pods={nalewp, zlewp, naprap, zprap};
	algo();
	
	
	debug() << tab;
	cout << "SURGERY COMPLETE\n";
	cout << wynp+wyn+wyns << "\n";
	for (string i : shortcut)
		cout << i << "\n";
	cout << "DONE" << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(10);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		test();
	return 0;
}