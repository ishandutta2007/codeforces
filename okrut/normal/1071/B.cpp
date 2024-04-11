#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug //
using namespace std;
int n, k;
vector <string> tab;
const int N=2000;
int dist[N][N], dyn[N][N];
vector <priority_queue <pair <pair <int, int>, int > > > kol;
bool pisz=false;
bool dfs (int x, int y)
{
	if (pisz) cout<<tab[x][y];
	pisz=true;
	if (x==n-1 && y==n-1) return true;
	if (x==n-1) return dfs(x,y+1);
	if (y==n-1) return dfs(x+1, y);
	if (dist[x+1][y]>dist[x][y+1]) return dfs(x, y+1);
	else return dfs(x+1, y);
}
void tabtest ()
{	
	debug ("tabtest\n");
	debug ("dist\n");
	rep(i,0,n) 
	{
		rep(j,0,n) debug ("%d ", dist[i][j]);
		debug ("\n");
	}
	debug ("dyn\n");
	rep(i,0,n) 
	{
		rep(j,0,n) debug ("%d ", dyn[i][j]);
		debug ("\n");
	}
}
int main ()
{
	ios_base::sync_with_stdio(false);
	cin>>n >>k;
	tab.resize(n);
	rep(i,0,n) cin>>tab[i];
	//liczymy odleglosc
	int l=0;
	rep(i,0,n) rep(j,0,n) dist[i][j]=dyn[i][j]=1e9;
	kol.resize(2);
	kol[0].push(mp(mp(tab[n-1][n-1], 0), (n-1)*n+n-1));
	pair <pair <char, int>, int> p;
	int x, y, z;
	rep(i,0,n*2-1)
	{
		z=0;
		while (!kol[l].empty())
		{
			p=kol[l].top();
			kol[l].pop();
			x=p.se/n;
			y=p.se%n;
			if (dist[x][y]<1e9) continue;
			z++;
			dist[x][y]=z;
			if (x>0) kol[1-l].push(mp(mp(-tab[x-1][y], -z), (x-1)*n+y));
			if (y>0) kol[1-l].push(mp(mp(-tab[x][y-1], -z),  x*n+y-1));
		}
		l=1-l;
	}
	rep(i,0,n) rep(j,0,n)
	{
		if (i==0 && j==0) dyn[i][j]=0;
		if (i>0) dyn[i][j]=min(dyn[i][j], dyn[i-1][j]);
		if (j>0) dyn[i][j]=min(dyn[i][j], dyn[i][j-1]);
		if (tab[i][j]!='a') dyn[i][j]++;
	}
	//tabtest();
	x=0; y=0;
	int d;
	pair <int, int> best=mp(0, 1e9);
	rep(i,0,n) rep(j,0,n) if (dyn[i][j]<=k)
	{
		/*if (dyn[i][j]==5) if (i>2)
		{
			debug ("%d %d - %d %d\n", i, j, dyn[i][j], dist[i][j]);
			debug ("vs %d %d - %d %d\n", best.fi, best.se, x, y);
		}*/
		d=1e8;
		if (i<n-1) d=min(d,dist[i+1][j]);
		if (j<n-1) d=min(d,dist[i][j+1]);
		if (i+j>best.fi)
		{
			best=mp(i+j, d);
			x=i; y=j;
		}
		if (i+j==best.fi) if (best.se>d)
		{
			best=mp(i+j, d);
			x=i; y=j;
		}
	}
	debug ("%d %d\n", x, y);
	if (best.se!=1e9) rep(i,0,best.fi+1) cout<<"a";
	else pisz=true;
	dfs(x,y);
	cout<<"\n";
}