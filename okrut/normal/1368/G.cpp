#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int T = 1<<17;
struct Tree
{
	int Sum[T+T], C[T+T];

	void mark (int left, int right, int x,  int a, int lewy, int prawy)
	{
		if (left<=lewy && right>=prawy) 
		{
			C[a]+=x;
			if (C[a]) Sum[a] = 0;
			else
			{
				if (lewy<prawy)
				{
					Sum[a]= Sum[a*2] + Sum[a*2+1];
				}
				else Sum[a]= 1;
			}
		}
		else
		{
			if (left<=mitte) mark(left, right, x, a*2, lewy, mitte);
			if (right>mitte) mark(left, right, x, a*2+1, mitte+1, prawy);
			
			if (C[a]==0) Sum[a] = Sum[a*2] + Sum[a*2+1];
		}
	}
	
	void init (int a, int lewy, int prawy)
	{
		if (lewy<prawy)
		{
			init(a*2, lewy, mitte);
			init(a*2+1, mitte+1, prawy);
			Sum[a] = Sum[a*2] + Sum[a*2+1];
		}
		else Sum[a] = 1;
		
		C[a] =0;
	}
	
	int sum ()
	{
		return Sum[1];
	}
};

const int N = 2e5;
vector <int> Black[N], White[N];
int Pre[N], Post[N], Dom[N+1]; //kostka domino
string B[N];
Tree BlackLabels;

int t = -1;
void dfs0 (int a)
{
	Pre[a] = ++t;
	for (int s: Black[a]) dfs0(s);
	Post[a] = t;
}
ll res = 0LL;

void dfs1 (int a)
{
	if (a>0)
	{
		debug ("w %d + %d\n", a, BlackLabels.sum()-1);
		BlackLabels.mark(Pre[a], Post[a], 1, 1,0,t);
		res += ll(BlackLabels.sum()) - 1;
	}
	
	for (int s: White[a])
	{
		dfs1(s);
	}
	
	if (a>0)
	{
		BlackLabels.mark(Pre[a], Post[a], -1, 1, 0, t);
	}
}

void drukGraf(int a, vector <int> *G)
{
	debug ("%d: ", a);
	for (int s: G[a]) debug ("%d ", s);
	debug ("\n");
	for (int s: G[a]) drukGraf(s, G);
}

int main ()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin>>n >>m;
	
	rep(i,0,n) cin>>B[i];
	
	int d = 0;
	rep(i,0,n) rep(j,0,m)
	{
		int v= i*m+j;
		int y = i, x = j;
		if (B[i][j]=='U') y++;
		if (B[i][j]=='D') y--;
		if (B[i][j]=='L') x++;
		if (B[i][j]=='R') x--;
		
		int u = y*m+x;
		
		if (Dom[v]==0) Dom[v] = Dom[u] = ++d;
	}
	
	
	rep(i,0,n) rep(j,0,m)
	{
		int v = i*m+j;
		int y = i, x = j;
		if (B[i][j]=='U') y+=2;
		if (B[i][j]=='D') y-=2;
		if (B[i][j]=='L') x+=2;
		if (B[i][j]=='R') x-=2;
		
		int u;
		if (y<0 or x<0 or x>=m or y>=n) 
		{
			u = N;
		}
		else u = y*m+x;
		
		
		u = Dom[u];
		v = Dom[v];
		
		if ((i^j)&1)
		{
			Black[u].pb(v);
		}
		else 
		{
			White[u].pb(v);
		}
	}
	
	
	debug ("White tree: \n");
	drukGraf(0,White);
	
	debug ("\n\nBlack Tree:\n");
	drukGraf(0,Black);
	
	
	dfs0(0);
	
	BlackLabels.init(1, 0, t);
	
	dfs1(0);
	
	printf ("%lld\n", ll(d)*ll(d) - res);
	
}