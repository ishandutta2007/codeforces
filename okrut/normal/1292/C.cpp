#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3e3+1;

vector <int> graf[N];
ll Dp[N][N], SubTree[N][N]; //result for a path, subtree of an edge

vector <int> L[N], R[N], L2[N], R2[N], stos;

void dfs1 (int a, int b)
{
	stos.pb(a);
	
	if (a < stos[0])
	{
		int s = stos.size();
		L[s].pb(a);
		L2[s].pb(stos[s-2]);
		R[s].pb(stos[0]);
		R2[s].pb(stos[1]);
	}
	for (int s: graf[a]) if (s!=b) dfs1(s,a);
	
	stos.pop_back();
}

void dfs0 (int a, int b)
{
	SubTree[a][b] = 1;
	for (int s: graf[a]) if (s!=b)
	{
		dfs0(s, a);
		SubTree[a][b]+=SubTree[s][a];
	}
	//debug ("SubTree[%d][%d] = %d\n", a, b, SubTree[a][b]);
}


int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n;
	scanf ("%d", &n);
	rep(i,1,n)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	rep(i,1,n+1) 
	{
		dfs0(i, 0);
		dfs1(i,0);
	}
	
	rep(i,1,n+1) rep(j,1,n+1)
	{
		if (SubTree[i][j]>0) debug ("SubTree[%d][%d] = %lld\n", i,j,SubTree[i][j]);
	}
	
	ll res = 0;
	rep(len,1,n+1)
	{
		int k = L[len].size();
		rep(i,0,k)
		{
			int l = L[len][i], r = R[len][i], l2 = L2[len][i], r2 = R2[len][i];
			
			debug ("process %d %d\n", l, r);
			
			Dp[l][r] = Dp[r][l] = max(Dp[r][l2], Dp[l][r2]) + SubTree[l][l2] * SubTree[r][r2];
			res = max(res, Dp[l][r]);
		}
	}
	
	rep(i,1,n+1) rep(j,1,n+1) debug ("Dp[%d][%d] = %lld\n", i, j, Dp[i][j]);
	
	printf ("%lld\n", res);
	
	
}