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

const int N = 2005;
int P[N][N], res[N], C[N], Pod[N];
bool ok = true;
vector <int> syny[N];
int rt;
void dfs (int a)
{
	for (int s: syny[a]) 
	{
		dfs(s);
		Pod[a]+=Pod[s];
	}
	
	
	if (C[a] > Pod[a]) 
	{
		debug ("blad %d: %d vs %d\n", a, C[a], Pod[a]);
		ok = false;
	}
	Pod[a]++;
	
	int it = 0;
	for (int s: syny[a])
	{
		rep(i,0,Pod[s])
		{
			if (it==C[a]) 
			{
				P[a][it] = a;
				it++;
			}
			P[a][it] = P[s][i];
			it++;
		}
	}
	if (it==C[a])
	{
		P[a][it] = a;
	}
}
int main ()
{
	int n;
	scanf ("%d", &n);
	rep(i,1,n+1)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		syny[a].pb(i);
		C[i] = b;
		if (a==0) rt = i;
	}
	
	dfs(rt);
	if (ok) 
	{
		printf ("YES\n");
		rep(i,0,n) res[P[rt][i]] = i+1;
		rep(i,1,n+1) printf ("%d ", res[i]);
		printf ("\n");
	}
	else printf ("NO\n");
}