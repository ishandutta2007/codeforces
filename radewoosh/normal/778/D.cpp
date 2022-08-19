#ifndef LOCAL
#define NDEBUG
#endif

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

const int nax=57;

int n, m;

char aktu[nax][nax];
char kon[nax][nax];

vector <pair <int,int> > wyn;

vector<char> pio=vector<char>{'U', 'U', 'D', 'D'};
vector<char> poz=vector<char>{'L', 'R', 'L', 'R'};

void ustaw_poz(int v, int u);
void ustaw_pio(int v, int u);

void ustaw(int v, int u)
{
	vector <char> tu;
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			tu.push_back(aktu[v+i][u+j]);
	if (tu==pio)
		return;
	if (tu==poz)
		return;
	if (tu[0]=='L')
	{
		ustaw_poz(v+1, u);
	}
	if (tu[0]=='U')
	{
		ustaw_pio(v, u+1);
	}
	if (tu[0]=='R')
	{
		ustaw_pio(v, u-1);
		if (tu[1]!='U')
			ustaw_pio(v, u+1);
	}
	if (tu[0]=='D')
	{
		ustaw_poz(v-1, u);
		if (tu[2]!='L')
			ustaw_poz(v+1, u);
	}
}

void ustaw_poz(int v, int u)
{
	vector <char> tu;
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			tu.push_back(aktu[v+i][u+j]);
	if (tu==poz)
		return;
	if (tu==pio)
	{
		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				aktu[v+i][u+j]=poz[2*i+j];
		wyn.push_back({v, u});
		return;
	}
	ustaw(v, u);
	ustaw_poz(v, u);
}

void ustaw_pio(int v, int u)
{
	vector <char> tu;
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			tu.push_back(aktu[v+i][u+j]);
	if (tu==pio)
		return;
	if (tu==poz)
	{
		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				aktu[v+i][u+j]=pio[2*i+j];
		wyn.push_back({v, u});
		return;
	}
	ustaw(v, u);
	ustaw_pio(v, u);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%s", aktu[i]+1);
	for (int i=1; i<=n; i++)
		scanf("%s", kon[i]+1);
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (aktu[i][j]==kon[i][j])
				continue;
			debug() << "start " << i << " " << j;
			if (aktu[i][j]=='U')
				ustaw_poz(i, j);
			else
				ustaw_pio(i, j);
		}
	}
	
	printf("%d\n", (int)wyn.size());
	for (int i=0; i<wyn.size(); i++)
		printf("%d %d\n", wyn[i].first, wyn[i].second);
	return 0;
}