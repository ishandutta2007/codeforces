#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf 
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 105;
const int A = 'z' - 'a' +1;
int Dp[N][N][A][2], St[N];

vector <pair <int,int> > graf[N];


int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	rep(i,0,m)
	{
		int a, b;
		char c;
		scanf ("%d %d %c", &a, &b, &c);
		graf[a].pb({b, c - 'a'});
		St[b]++;
	}
	
	queue <int> kol;
	vector <int> topo;
	rep(i,1,n+1) if (St[i]==0) kol.push(i);
	while (!kol.empty())
	{
		int v = kol.front();
		kol.pop();
		topo.pb(v);
		for (auto s: graf[v]) if ((--St[s.fi])==0) kol.push(s.fi);
	}
	
	reverse(topo.begin(), topo.end());
	
	for (int mux: topo) for (int lux: topo) rep(c,0,A)
	{
		//na razie jest 0, przegrywamy:
		for (auto s: graf[mux]) if (s.se >= c)
		{
			Dp[mux][lux][c][0] |= (Dp[s.fi][lux][s.se][1]^1);
		}
		for (auto s: graf[lux]) if (s.se >= c)
		{
			Dp[mux][lux][c][1] |= (Dp[mux][s.fi][s.se][0]^1);
		}
	}
	
	rep(mux,1,n+1)
	{
		rep(lux,1,n+1) 
		{
			if (Dp[mux][lux][0][0]) printf ("A");
			else printf ("B");
		}
		printf ("\n");
	}
}