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

const int N = 2e5+10;
int D[2][N];
vector <int> graf[N];
void bfs (int s, int *T)
{
	queue <int> kol;
	T[s]= 0;
	kol.push(s);
	while (!kol.empty())
	{
		int v = kol.front();
		kol.pop();
		for (int u: graf[v]) if (T[u]==-1)
		{
			T[u] = T[v]+1;
			kol.push(u);
		}
	}
}
int main ()
{
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	vector <int> spe(k);
	for (int &a: spe) scanf ("%d", &a);
	
	rep(i,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	rep(i,0,2) rep(j,0,n+1) D[i][j] = -1;
	bfs(1, D[0]);
	bfs(n, D[1]);
	
	
	int ile = 0;
	
	rep(i,1,n+1) if (D[0][i]==D[1][i]) ile++;
	if (ile>1)
	{
		printf ("%d\n", D[0][n]);
		return 0;
	}
	
	int BigB2 = -1e6;
	int res = 1;
	
	vector <pair <int, int> > cmp, work;
	for (int i: spe) cmp.pb({D[1][i] - D[0][i], i});
	for (int i: spe) work.pb({D[0][i] - D[1][i], i});
	sort(work.begin(), work.end());
	sort(cmp.begin(), cmp.end());
	while (!work.empty())
	{
		//bool addme = false;
		int a = work.back().se;
		/*
		while (!cmp.empty() && cmp.back().fi >= work.back().fi)
		{
			int b =	cmp.back().se;
			debug ("cmp %d (%d)\n", b, cmp.back().fi);
			if (a==b)
			{
				addme = true;
			}
			else
			{
				BigB2 = max(BigB2, D[1][b]);
			}
			cmp.pop_back();
		}
		*/
		
		debug ("for %d: best B %d = (%d + %d)\n", a, BigB2, D[0][a], BigB2);
		
		res = max(res, D[0][a] + BigB2+1);
		
		BigB2 = max(BigB2, D[1][a]);
		work.pop_back();
	}
	
	res = min(res, D[0][n]);
	printf ("%d\n", res);
}