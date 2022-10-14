#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug // 
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+10;
const int T = 1<<18;
int res[N], tree[T+T];



void add (int a)
{
	a+=T;
	while (a>0)
	{
		tree[a]++;
		a/=2;
	}
}

int pos (int x)
{
	int ret = 0;
	int pot = T/2;
	int a = 1;
	while (pot>0)
	{
		if (tree[a*2]>=x) 
		{
			a *= 2;
		}
		else
		{
			x-=tree[a*2];
			a = a*2+1;
			ret+=pot;
		}
		pot/=2;
	}
	return ret;
}

int main ()
{
	int n, m;
	
	scanf ("%d", &n);
	vector <pair <int,int > > tab(n);
	for (auto &p: tab) 
	{
		scanf ("%d", &p.fi);
	}
	rep(i,0,n) tab[i].se = i;
	
	sort(tab.begin(), tab.end(), [] (pair <int, int> a, pair <int, int> b) {if (a.fi!=b.fi) return a.fi > b.fi; return a.se < b.se;});
	
	scanf ("%d", &m);
	vector <pair <pair <int, int>, int> > query(m);
	for (auto &p: query) scanf ("%d %d", &p.fi.fi, &p.fi.se);
	rep(i,0,m) query[i].se = i;
	sort(query.begin(), query.end());
	
	
	int p = 0;
	rep(i,1,n+1)
	{
		add(tab[i-1].se);
		
		while (p<m && query[p].fi.fi==i)
		{
			res[query[p].se] = pos(query[p].fi.se);
			p++;
		}
	}
	
	for (auto &para: tab) swap(para.fi, para.se);
	sort(tab.begin(), tab.end());
	rep(i,0,m) 
	{
		res[i] = tab[res[i]].se;
	}
	rep(i,0,m) printf ("%d\n", res[i]);
}