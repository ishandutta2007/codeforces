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

const int T = 1<<17;

int val[N], tree[T+T]; //to zwraca maksimum
bool res[T+T];
void mark (int l, int r)
{
	l+=T;
	r+=T;
	while (l<r)
	{
		res[l] = true;
		res[r] = true;
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (l==r) res[l] = true;
}
bool read (int a)
{
	a+=T;
	while (a>0)
	{
		if (res[a]) return true;
		a/=2;
	}
	return false;
}
int mini (int l, int r)
{
	l+=T;
	r+=T;
	int ret = N;
	while (l<r)
	{
		ret = min(ret, tree[l]);
		ret = min(ret, tree[r]);
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (l==r) ret = min(ret, tree[l]);
	return ret;
}

int n;
vector <pair <int, int> > tab;
int POS[N];
bool check (int d)
{
	vector <bool> ok(n, false), dp(n, false);
	
	rep(i,0,n-1) ok[i] = ( abs(val[i] - val[i+1]) <=d);
	rep(i,0,T+T) res[i] = false;
	
	rep(i,0,T+T) tree[i] = N;
	rep(i,0,n) 
	{
		tree[T+i] = tab[i].se;
		POS[tab[i].se] = i;
	}
	for (int i = T-1; i>0; i--) tree[i] = min(tree[i*2], tree[i*2+1]);
	
	debug ("\ncheck %d\n", d);
	
	dp[0] = true;
	rep(i,0,n) 
	{
		//usun mnie z drzewa
		int a = POS[i]+T;
		tree[a] = N;
		while (a>1)
		{
			a/=2;
			tree[a] = min(tree[a*2], tree[a*2+1]);
		}
		
		dp[i] = dp[i] or read(i);
		
		if (!ok[i] || !dp[i]) continue;
		
		debug ("da sie %d %d\n", i, i+1);
		
		int m;
		rep(repete,0,2)
		{
			if (repete) 
			{
				m = i;
			}
			else
			{
				m=i+1;
			}
		
			auto li = lower_bound(tab.begin(), tab.end(), mp(val[m] - d, 0));
			auto ri = lower_bound(tab.begin(), tab.end(), mp(val[m] +d+1, 0));
			ri--;
			int l = li - tab.begin();
			int r = ri - tab.begin();
			
			int d1 = mini(0,l-1);
			int d2 = mini(r+1,n-1);
			int d = min(d1, d2)-1; //co najwyzej do tego moge sie dostac
			d = min(d, n-1);
			
			if (d>i+1) mark(i+2, d);
			
			debug ("dla %d = ide do %d (vs %d)\n", m, d, i+1);
		}
	}
	
	
	return dp[n-1] or dp[n-2];
}
int main ()
{
	scanf ("%d", &n);
	n+=2;
	tab.resize(n);
	rep(i,0,n) 
	{
		tab[i].se = i;
		scanf ("%d", &tab[i].fi);
		val[i] = tab[i].fi;
	}
	sort(tab.begin(), tab.end());
	rep(i,0,n) tree[T+i] = tab[i].se;
	for (int i = T-1; i>0; i--) tree[i] = max(tree[i*2], tree[i*2+1]);
	
	int l = 0;
	int r = 1e9;
	
	while (l<r)
	{
		int mid = (l+r)/2;
		if (check(mid)) r = mid;
		else l = mid+1;
	}
	printf ("%d\n", l);
}