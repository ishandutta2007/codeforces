#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int T = 1<<19;

int tree[T+T];

void mark (int a, int val)
{
	a+=T;
	while (a>0)
	{
		tree[a] = min(tree[a], val);
		a/=2;
	}
}	
void init ()
{
	rep(i,0,T+T) tree[i] = T-1;
}
int mini (int l, int r)
{
	l+=T;
	r+=T;
	int res = T-1;
	while (l<r)
	{
		res = min(res, tree[l]);
		res = min(res, tree[r]);
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (l==r) res = min(res, tree[l]);
	return res;
}

int tab[T], quit[T];

map <int, int> mapa;
int main ()
{
	int n;
	scanf ("%d", &n);
	init();
	set <int> wor;
	rep(i,0,n)
	{
		scanf ("%d", &tab[i]);
		wor.insert(tab[i]);
		wor.insert((tab[i]-1)/2);
		tab[2*n+i] = tab[n+i] = tab[i];
	}
	
	int y = 0;
	
	for (int x: wor) mapa[x] = y++;
	
	for (int p = n*3-1; p>=0; p--)
	{
		quit[p] = mini(0, mapa[(tab[p]-1)/2]);
		mark(mapa[tab[p]], p);
		debug ("%d = quit[%d] = %d\n", tab[p], p, quit[p]);
	}
	
	init();
	rep(i,0,n*3) mark(i, quit[i]);
	
	rep (p,0,n)
	{
		int end = min(quit[p], mini(p,quit[p]-1)); //tutaj sie skonczy
		if (end==T-1) printf ("-1 ");
		else printf ("%d ", end-p);
	}
	printf ("\n");
}