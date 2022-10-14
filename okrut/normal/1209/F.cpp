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
const ll mod = 1e9+7;
const int N = 1e5+1;
const int M = 3000000;
vector <pair <int, int> > graf[M+M];
vector <int> phase[M+M];
bitset <M+M> vst;
ll res[M];
int n, m;
void path (int a, int b, int x)
{
	while (x>9)
	{
		int y = ++n;
		graf[y].pb(mp(x%10, b));
		b = y;
		x/=10;
	}
	graf[a].pb(mp(x, b));
}
queue <pair <ll, int> > kol; 
int main ()
{
	scanf ("%d %d", &n, &m);
	int g = n;
	int a, b;
	rep(i,1,m+1)
	{
		scanf ("%d %d", &a, &b);
		path(a, b, i);
		path(b,a,i);
	}
	vst.set();
	phase[0].pb(1);
	int p= 1;
	kol.push(mp(0,0));
	vst[1] = 0;
	while (!kol.empty())
	{
		pair <ll, int> q = kol.front();
		kol.pop();
		vector <pair <int, int> > go;
		
		
		for (int x: phase[q.se]) 
		{
			res[x] = q.fi;
			for (auto s: graf[x]) go.pb(s);
		}
		sort(go.begin(), go.end());
		int y = 0;
		rep(c,0,10)
		{
			vector <int> rob;
			while (y <(int)go.size() && go[y].fi==c)
			{
				if (vst[go[y].se]) 
				{
					rob.pb(go[y].se);
					vst[go[y].se] = false;
				}
				y++;
			}
			if (!rob.empty()) 
			{
				phase[p] = rob;
				kol.push(mp((q.fi*10LL + ll(c))%mod, p));
				p++;
			}
		}
	}
	rep(i,2,g+1) printf ("%lld\n", res[i]);
}