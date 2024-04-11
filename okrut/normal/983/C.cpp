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
const int inf = 1e9;
int dp[N][10][10][10][10], F[N], T[N];

int go (int from, int to, vector <int> &pass)
{
	int dol = min(from, to), gora = max(from, to);
	int ret = gora - dol;
	for (int &p: pass)
	{
		if (dol <=p && p <= gora) 
		{
			ret++;
			p = 0;
		}
	}
	sort(pass.begin(), pass.end());
	return ret;
}

inline void better (int &a, int b)
{
	a = min(a, b);
}
int main ()
{
	//ios_base::sync_with_stdio(false);
	
	memset(dp, 0x7f,  N*10000*sizeof(int));
	
	int n;
	scanf ("%d", &n);
	rep(i,0,n) scanf ("%u %u", &F[i], &T[i]);
	
	dp[0][0][0][0][T[0]] = F[0]; //after picking the i-th one
	
	rep(i,0,n-1) rep(a,0,10) rep(b,a,10) rep(c,b,10) rep(d,c,10) if (dp[i][a][b][c][d] < inf)
	{
		debug ("state\n");
		rep(mid,1,10)
		{
			int pr = dp[i][a][b][c][d];
			vector <int> pass = {a,b,c,d};
			pr += go(F[i], mid, pass);
			pr += go(mid, F[i+1], pass);
			if (pass[0]==0) 
			{
				pass[0] = T[i+1];
				sort(pass.begin(), pass.end());
				pr++;
				better(dp[i+1][pass[0]][pass[1]][pass[2]][pass[3]], pr);
				
				if (false)
				{
					debug ("picked up %d ( ", i+1);
					for (int p: pass) debug ("%d ", p);
					debug (") for %d\n", pr);
				}
			}
			
		}
	}
	
	int res = inf;
	rep(a,0,10) rep(b,a,10) rep(c,b,10) rep (d,c,10) if (dp[n-1][a][b][c][d] < inf)
	{
		int mid = F[n-1];
		debug ("mid = %d\n", mid);
		int gora = mid;
		int dol = mid;
		vector <int> pass = {a,b,c,d};
		int cnt = 0;
		for (int p: pass) if (p!=0)
		{
			cnt++;
			gora = max(p,gora);
			dol = min(p,dol);
		}
		
		int pr = dp[n-1][a][b][c][d] + cnt + gora - dol + min(gora - mid, mid - dol);
		
		debug ("can do it for %d (%d %d %d %d)\n", pr, cnt, dol, mid, gora);
		
		better(res, pr);
	}
	printf ("%d\n", res);
}