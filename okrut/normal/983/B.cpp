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

const int N = 5004;
const int T = 1<<13;
int F[N][N], Res[N*N], tree[T+T];

void mark (int a, int x)
{
	a+=T;
	while (a>0)
	{
		tree[a] = max(tree[a], x);
		a/=2;
	}
}
int maks (int l, int r)
{
	l+=T;
	r+=T;
	int ret = 0;
	while (l<r)
	{
		ret = max(tree[l], ret);
		ret = max(tree[r], ret);
		r = (r-1)/2;
		l = (l+1)/2;
	}
	if (l==r) ret = max(ret, tree[l]);
	
	return ret;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	rep(i,0,n) scanf ("%d", &F[0][i]);
	
	rep(len,1,n)
	{
		rep(i,0,n-len) F[len][i] = F[len-1][i] ^ F[len-1][i+1];
	}
	
	
	if (false)
	{
		rep(i,0,n)
		{
			rep(len,0,n-i) printf ("%d ", F[len][i]);
			printf ("\n");
		}
		return 0;
	}
	
	int q;
	scanf ("%d", &q);
	vector <pair <pair <int, int>, int> > Q(q);
	rep(i,0,q)
	{
		scanf ("%d %d", &Q[i].fi.fi, &Q[i].fi.se);
		Q[i].se = i;
		Q[i].fi.fi--;
		Q[i].fi.se--;
	}
	sort(Q.begin(), Q.end());
	reverse(Q.begin(), Q.end());
	
	int st = n-1;
	rep(i,0,q)
	{
		auto p = Q[i];
		while (st>=p.fi.fi)
		{
			rep(len,0,n-st) 
			{
				mark(len+st, F[len][st]);
			}
			st--;
		}
		
		Res[p.se] = maks(p.fi.fi, p.fi.se);
	}
	rep(i,0,q) printf ("%d\n", Res[i]);
}