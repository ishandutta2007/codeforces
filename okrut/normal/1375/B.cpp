#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 300;
int tab[N][N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n, m;
		scanf ("%d %d", &n, &m);
		rep(i,0,n) rep(j,0,m) scanf ("%d", &tab[i][j]);
		
		bool ok = true;
		rep(i,0,n) rep(j,0,m)
		{
			int cnt = 4;
			if (i==0 or i==n-1) cnt--;
			if (j==0 or j==m-1) cnt--;
			if (tab[i][j]>cnt) ok = false;
			tab[i][j] = cnt;
		}
		
		if (ok)
		{
			printf ("YES\n");
			rep(i,0,n) 
			{
				rep(j,0,m) printf ("%d ", tab[i][j]);
				printf ("\n");
			}
		}
		else printf ("NO\n");
	}	
	
}