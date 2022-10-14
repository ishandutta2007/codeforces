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
#define INF 1000
const int N=501;
int dist[N][N];
int n;
vector <vector <int> > graf; //graf zapytan
void graj (vector <int> &tab) //to sa moje wierzcholki
{
	vector <bool> on;
	on.resize(n+1,false);
	for (int s: tab) on[s]=true;
	pair <int, int> p, best=mp(INF,0); //bede szukal minimum
	int x;
	for (int k: tab) //jezeli zapytam o ok
	{
		p.fi=0;
		p.se=k;
		for (int s: graf[k]) if (on[s]) //czy rozwazam s
		{
			x=0;
			for (int v: tab) if (dist[k][v]>dist[s][v]) x++; //bedzie w mojej skladowej
			p.fi=max(p.fi, x);
		}
		best=min(best, p);
	}
	
	int k=best.se;
	
	cout<<k <<"\n";
	fflush(stdout);
	string slo;
	cin>>slo;
	if (slo=="FOUND") return;
	int a;
	cin>>a;
	vector <int> rob;
	for (int v: tab) if (dist[k][v]>dist[a][v]) rob.pb(v);
	graj(rob);
}
int main ()
{
	int m, k;
	int a, b;
	cin>>n >>m;
	graf.resize(n+1);
	rep(i,1,n+1) rep(j,1,n+1) dist[i][j]=INF;
	rep(i,1,n+1) dist[i][i]=0;
	rep(i,0,m)
	{
		cin>>k >>a;
		rep(i,1,k)
		{
			cin>>b;
			graf[a].pb(b);
			graf[b].pb(a);
			dist[a][b]=1;
			dist[b][a]=1;
			a=b;
		}
	}
	rep(b,1,n+1) rep(a,1,n+1) rep(c,1,n+1) dist[a][c]=min(dist[a][c], dist[a][b]+dist[b][c]);
	vector <int> tab;
	tab.resize(n);
	rep(i,0,n) tab[i]=i+1;
	
	rep(i,0,n) graj(tab);
}