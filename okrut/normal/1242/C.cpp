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

const int K = 15;
set <ll> mam[K];
ll sum[K];
pair <ll, ll> res[1<<K][K];
vector <bool> vst;
ll av;
pair <ll, ll> zap[K];
int mask, k;
ll gv;
bool dfs (int a, ll give, int b=-1)
{
	if (a==b)
	{
		if (give==gv) return true;
		else return false;
	}
	
	if (b==-1) 
	{
		gv = give;
		b= a;
	}
	if (!vst[a]) return false;
	
	
	vst[a] = false;
	
	mask+=1<<a;
	zap[a].fi = give;
	
	ll want = av - (sum[a] - give);
	
	rep(j,0,k) if (mam[j].count(want))
	{
		if (dfs(j, want, b)) 
		{
			zap[j].se = a+1;
			return true;
		}
		else return false;
	}
	return false;
}
int main ()
{
	int n;
	scanf ("%d", &k);
	rep(i,0,k)
	{
		scanf ("%d", &n);
		ll a;
		rep(j,0,n) 
		{
			scanf ("%lld", &a);
			sum[i]+=a;
			mam[i].insert(a);
		}
	}
	ll tot = 0LL;
	rep(i,0,k) tot+=sum[i];
	if (tot % ll(k) !=0LL) 
	{
		printf ("No\n");
		return 0;
	}
	av = tot/ll(k);
	
	vector <bool> ok (1<<k, false); //czy taki uklad jest ok
	
	rep(s,0,k)
	{
		for (ll out: mam[s])
		{
			vst.clear();
			vst.resize(k, true);
			mask = 0;
			if (dfs(s, out))
			{
				ok[mask] = true;
				rep(i,0,k) if (mask & (1<<i)) res[mask][i] = zap[i];
			}
		}
	}
	
	for (int m1 = 1; m1<(1<<k); m1++)
	{
		for (int m2 = (m1-1)&m1; m2>=0; m2 = (m2-1)&m1)
		{
			if (ok[m2] && ok[m1-m2])
			{
				ok[m1] = true;
				rep(i,0,k) if (m2 & (1<<i)) res[m1][i] = res[m2][i];
				rep(i,0,k) if ((m1-m2) & (1<<i)) res[m1][i] = res[m1-m2][i];
			}
			if (m2==0 || ok[m1]) break;
		}
	}
	
	int m = (1<<k) -1;
	if (ok[m])
	{
		printf ("Yes\n");
		rep(i,0,k) printf ("%lld %lld\n", res[m][i].fi, res[m][i].se);
	}
	else printf ("No\n");
}