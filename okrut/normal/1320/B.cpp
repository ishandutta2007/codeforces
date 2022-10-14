#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+10;
vector <int> graf[N], revgraf[N];
int Dist[N]; //dist from t

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n, m;
	scanf ("%d %d", &n, &m);
	
	rep(i,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		revgraf[b].pb(a);
	}
	
	rep(i,1,n+1) Dist[i] = N;
	
	int k;
	scanf ("%d", &k);
	vector <int> path(k);
	for (int &p: path) scanf ("%d", &p);
	int s = path[0], t = path.back();
	
	queue <int> kol;
	kol.push(t);
	Dist[t] = 0;
	while (!kol.empty())
	{
		int v = kol.front();
		kol.pop();
		for (int x: revgraf[v]) if (Dist[x]==N)
		{
			Dist[x] = Dist[v]+1;
			kol.push(x);
		}
	}
	
	int maks = 0, mini = 0;
	
	int prv = -1;
	int cnt = -1;
	
	for (int p: path) if (p!=t)
	{
		if (prv>0)
		{
			//na pewno przyjechalem nie tak
			if (Dist[p]+1 != Dist[prv])
			{
				maks++;
				mini++;
			}
			else if (cnt>1)
			{
				maks++;
			}
		}
		
		cnt = 0;
		for (int nxt: graf[p]) cnt += (Dist[nxt]+1==Dist[p]? 1 : 0);
		
		prv = p;
	}
	
	printf ("%d %d\n", mini, maks);
}