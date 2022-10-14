#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int K = 10;
vector <pair <int, int> > graf[N];
vector <vector <int> > Layers[K];
vector <int> V[K], C[K];
int Tab[N];

int n, res = 0, kmax;
void backtrack (int k, int x = 1)
{
	/*
	debug ("backtrack for %d: \n", k);
	rep(i,1,n+1) debug ("%d ", Tab[i]);
	debug ("\n");
	*/
	
	if (k==kmax)
	{
		res+=x;
		return;
	}
	
	int c = 0;
	for (auto wek: Layers[k]) 
	{
		if (wek.empty() or wek[0]>0)
		{
			bool ok = true;
			for (int y: wek) if (Tab[y]) ok = false;
			if (ok)
			{
				for (int y: wek) Tab[y]++;
				backtrack(k+1, x * C[k][c]);
				for (int y: wek) Tab[y]--;
			}
		}
		c++;
	}
}

bool good (vector <int> &tab)
{
	sort(tab.begin(), tab.end());
	rep(i,1,(int)tab.size()) if (tab[i]==tab[i-1]) return false;
	return true;
}

bool same (vector <int> &t1, vector <int> &t2)
{
	int s = t1.size();
	rep(i,0,s) if (t1[i]!=t2[i]) return false;
	return true;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int m, k;
	scanf ("%d %d %d", &n, &m, &k);
	kmax = k+1;
	
	rep(i,0,m)
	{
		int a, b, c;
		scanf ("%d %d %d", &a, &b, &c);
		graf[a].pb({c,b});
	}
	rep(i,1,n+1)
	{
		sort(graf[i].begin(), graf[i].end());
		V[graf[i].size()].pb(i);
	}
	
	rep(i,1,K)
	{	
		vector <int> rob(V[i].size());
		if (V[i].size()==0)
		{
			Layers[i].pb(rob);
			C[i].pb(i);
		}
		else
		{
			rep(j,0,i)
			{
				int x = 0;
				for (int v: V[i]) rob[x++] = graf[v][j].se;
				
				if (good(rob))
				{
					Layers[i].pb(rob);
					C[i].pb(1);
				}
			}
			sort(Layers[i].begin(), Layers[i].end());
			rep(j,1,(int)Layers[i].size()) if (same(Layers[i][j-1], Layers[i][j]))
			{
				Layers[i][j-1][0] = -1;
				C[i][j]+=C[i][j-1];
			}
		}
	}
	
	backtrack(1);
	printf ("%d\n", res);
}