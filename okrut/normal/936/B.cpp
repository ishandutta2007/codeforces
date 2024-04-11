#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5+4;
vector <int> graf[N], graf2[N];
bitset <N> vst, in;
bool cycle (int a) 
{
	if (in[a]) return true;
	vst[a] = true;
	in[a] = true;
	
	for (int s: graf2[a]) 
	{
		if (in[s]) return true;
		if (!vst[s] && cycle(s)) return true;
	}
	in[a] = false;
	return false;
}

int tab[N][2];
int n, m;
int main ()
{
	memset(tab, 0, sizeof tab);
	int a, b, c;
	scanf ("%d %d", &n, &m);
	vector <int> sto(n+1, 0);
	rep(i,0,n) 
	{
		scanf ("%d", &c);
		rep(j,0,c) 
		{
			scanf ("%d", &b);
			graf[b].pb(i+1);
			
			graf2[i+1].pb(b);
			sto[i+1]++;
		}
	}
	int s;
	scanf ("%d", &s);
	
	queue <pair <int, int> > kol;
	
	rep(i,1,n+1) if (sto[i]==0) 
	{
		tab[i][1] = -1;
		kol.push(mp(i,1));
	}
	
	
	{
		pair <int, int> p;
		while (!kol.empty()) 
		{
			p = kol.front();
			kol.pop();
			for (int v: graf[p.fi]) if (tab[v][p.se^1]==0) 
			{
				tab[v][p.se^1] = (n+1)*p.se + p.fi;
				kol.push(mp(v, p.se^1));
			}
		}
	}
	
	if (tab[s][0]!=0) 
	{
		printf ("Win\n");
		int p = s;
		while (p>0)
		{
			printf ("%d ", p%(n+1));
			p = tab[p%(n+1)][p/(n+1)];
		}
		printf ("\n");
	}	
	else
	{
		vst.reset();
		in.reset();
		if (cycle(s)) printf ("Draw\n");
		else printf ("Lose\n");
	}
}