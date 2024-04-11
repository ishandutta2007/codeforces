#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;

namespace mincost {
	typedef int T;
	struct edge {
		T cap, flow, pay;
		int b;
	};
	const int N = 2600;
	const T INF = 1e8;
	vector <int> graf[N];
	vector <edge> e;
	T D[N], Cur[N], Vol[N];
	int Pre[N], Eid[N];
	void addEdge (int a, int b, T cap, T pay, T flow = 0) {
		graf[a].pb(e.size());
		e.pb({cap, flow, pay, b});
		graf[b].pb(e.size());
		e.pb({0, 0, -pay, a});
	}
	bool ford(int n, int s, int t) {
		rep(a,0,n) D[a] = INF;
		D[s] = 0;
		rep(k,0,n) {
			for (int i=0; i<(int)e.size(); i++) if (e[i].cap > e[i].flow) {
				int b = e[i].b, a = e[i^1].b;
				T d = D[a] + e[i].pay;
				if (D[a]==INF || D[b] <= d) continue;
				D[b] = d;
			}
		}
		return (D[t]<INF);
	}
	bool dijkstra (int n, int s, int t) {
		priority_queue <pair <T, int> > kol;
		kol.push(mp(0,s));
		rep(i,0,n) Cur[i] = INF;
		Cur[s] = 0;
		Vol[s] = INF;
		while (!kol.empty()) {
			auto p = kol.top();
			kol.pop();
			if (Cur[p.se] > -p.fi) continue;
			T d;
			for (int x: graf[p.se]) if (e[x].cap > e[x].flow) {
				if ((d= e[x].pay + D[p.se] - D[e[x].b] -p.fi) < Cur[e[x].b]) {
					Cur[e[x].b] = d;
					Pre[e[x].b] = p.se;
					Vol[e[x].b] = min(Vol[p.se], e[x].cap - e[x].flow);
					Eid[e[x].b] = x;
					kol.push(mp(-d, e[x].b));
				}
			}
		}
		rep(i,0,n) D[i]= Cur[i] + D[i];
		return (D[t]<INF);
	}
	pair <T, T> flow (int n, int s, int t) {
		pair <T, T> ret = mp(0,0);
		ford(n,s,t); //in case of negative edges
		while (dijkstra(n,s,t)) {
			int v = t;
			while (v!=s) {
				e[Eid[v]].flow+=Vol[t];
				e[Eid[v]^1].flow-=Vol[t];
				v = Pre[v];
			}
			ret.fi+=Vol[t];
			ret.se+=D[t] * Vol[t];
		}
		return ret;
	}
}

const int N = 50;
char tab[N][N];
int edge[N][N];
int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	rep(i,0,n) rep(j,0,n) tab[i][j] = '?';
	rep(i,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		a--; b--;
		tab[a][b] = '1';
		tab[b][a] = '0';
	}
	
	int play = (n * (n-1))/2;
	//0 zrodlo, 1 ujcie [2, n+1] - team, [n+2, ... ] mecze
	int mecz = 0, x=0;
	
	rep(a,0,n) rep(b,0,n) edge[a][b] = -1;
	
	rep(a,0,n) rep(b,0,a)
	{
		int p = n+2+mecz;
		mecz++;
		
		mincost::addEdge(0, p, 1, 0);
		x+=2;
		
		if (tab[a][b]!='0') 
		{
			mincost::addEdge(p, a+2, 1, 0);
			edge[a][b] = x;
			x+=2;
		}
		if (tab[b][a]!='0') 
		{
			mincost::addEdge(p, b+2, 1, 0);
			edge[b][a] = x;
			x+=2;
		}
	}
	
	rep(a,0,n) rep(b,1,n)
	{
		mincost::addEdge(a+2, 1, 1, b*b);
	}
	
	pair <int, int> res = mincost::flow(n+2+play, 0, 1);
	
	assert(res.fi == play);
	
	rep(a,0,n) 
	{
		rep(b,0,n) 
		{
			if (a==b || edge[a][b]==-1) printf ("0");
			else if (mincost::e[edge[a][b]].flow==1) printf("1");
			else printf ("0");
		}
		printf ("\n");
	}
	
}