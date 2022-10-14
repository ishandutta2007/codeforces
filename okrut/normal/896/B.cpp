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

const int N = 1005;
int tab[N];
int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, m, c;
	scanf ("%d %d %d", &n, &m, &c);
	
	int pol = c/2;
	int stan = 0;
	rep(quey,0,m)
	{
		int x;
		scanf ("%d", &x);
		int ans = 0;
		if (x<=pol)
		{
			rep(i,1,n+1)
			{
				if (tab[i]==0) 
				{
					tab[i] = x;
					ans = i;
					stan++;
					break;
				}
				if (tab[i] > x)
				{
					tab[i] = x;
					ans = i;
					break;
				}
			}
		}
		else
		{
			for (int i=n; i>0; i--)
			{
				if (tab[i]==0)
				{
					tab[i] = x;
					ans = i;
					stan++;
					break;
				}
				if (tab[i] < x)
				{
					tab[i] = x;
					ans = i;
					break;
				}
			}
		}
		printf ("%d\n", ans);
		fflush(stdout);
		
		if (stan==n) break;
	}
}