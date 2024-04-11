#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, pair <int, int> > tup; //result, representant, #brothers

const int N = 5e5+100;
vector <int> tree[N];
vector <pair <int, pair <int, int> > > Rec[N];
vector <tup> Weks[N];
ll Depth[N], Calc[N], Res[N];
int w;
vector <tup> *dfs (int v)
{
	vector <tup> *ret = &Weks[w++];
	
	for (int s: tree[v])
	{
		Depth[s] = Depth[v]+1;
		vector <tup> *son = dfs(s);
		
		if (son->size() > ret->size()) swap(son, ret);
		
		int k = son->size();
		int n = ret->size();
		
		for (int i=n-1; i>=0; i--)
		{
			if ( (--k) < 0) break;
			tup a = (*ret)[i], b = (*son)[k];
			
			a.fi += (Depth[v]+1) * b.se.se;
			b.fi += (Depth[v]+1) * a.se.se;
			
			(*ret)[i] = { a.fi, {a.se.fi, a.se.se+b.se.se}};
			
			Rec[v].pb({b.se.fi, {a.se.fi, b.fi - a.fi} });
		}
	}
	
	ret->pb( {Depth[v], {v, 1} });
	
	return ret;
}


void calc (int v)
{
	debug ("calc from %d = %d\n", v, Calc[v]);
	reverse(Rec[v].begin(), Rec[v].end());
	for (auto s: Rec[v]) 
	{
		debug ("to %d from %d (%d+%d)\n", s.fi, s.se.fi, Calc[s.se.fi],  s.se.se);
		Calc[s.fi] = s.se.se + Calc[s.se.fi];
	}
	for (int s: tree[v]) calc(s);
}

void res (int v)
{
	Res[v] += Calc[v];
	for (int s: tree[v])
	{
		Res[s] = Res[v];
		res(s);
	}
}

int main ()
{
	int n;
	scanf ("%d", &n);
	
	rep(i,1,n+1)
	{
		int b;
		scanf ("%d", &b);
		tree[b].pb(i);
	}
	
	int rt = tree[0][0];
	
	vector <tup> *wek = dfs(rt);
	
	for (auto t: (*wek))
	{
		debug ("in %d we have %d\n", t.se.fi, t.fi);
		Calc[t.se.fi] = t.fi;
	}
	calc(rt);
	
	debug ("policzylem Calc: \n");
	rep(i,1,n+1) debug ("%d ", Calc[i]);
	debug ("\n");
	
	res(rt);
	
	rep(i,1,n+1) printf ("%lld ", Res[i]);
	printf ("\n");
}