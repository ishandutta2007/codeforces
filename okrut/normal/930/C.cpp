#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5+10;
const int T = 1<<19;
int tree[T+T];
void mark (int x, int y)
{
	int a = x+T;
	tree[a] = y;
	while (a>1)
	{
		a/=2;
		tree[a] = max(tree[a*2], tree[a*2+1]);
	}
}
int maks (int l, int r)
{
	l+=T;
	r+=T;
	int ret = 0;
	while (l<r)
	{
		ret = max(ret, tree[l]);
		ret = max(ret, tree[r]);
		r = (r-1)/2;
		l = (l+1)/2;
	}
	if (l==r) ret = max(ret, tree[l]);
	return ret;
}

int tab[N], ros[N], mal[N], ile[N];

int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	int stan=0, a, b;
	rep(i,0,n)
	{
		scanf ("%d %d", &a, &b);
		tab[a]++;
		tab[b+1]--;
	}
	stan=0;
	
	rep(i,1,m+1)
	{
		stan+=tab[i];
		ile[i] = stan;
		ros[i] = maks(0, stan)+1;
		mark(stan, ros[i]);
	}
	memset(tree, 0, sizeof tree);
	stan=-tab[m+1];
	for (int i=m; i>=1; i--)
	{
		mal[i] = maks(0, stan)+1;
		mark(stan, mal[i]);
		
		stan-=tab[i];
	}
	rep(i,1,m+1)
	{
		debug ("%d %d\n", ros[i], mal[i]);
	}
	int res = mal[2];
	int naj=0;
	stan=0;
	rep(i,2,m)
	{
		if (ros[i-1]>naj)
		{
			naj = ros[i-1];
			stan=ile[i-1];
		}
		if (stan> ile[i] && ile[i] < ile[i+1]) res = max(res, naj + mal[i+1]);
		else
		{
			res = max(res, naj+mal[i+1]+1);
		}
	}
	res = max(res, ros[m-1]);
	printf ("%d\n", res);
}