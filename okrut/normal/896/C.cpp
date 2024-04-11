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

const int mod = 1e9+7;
int seed;
int rnd ()
{
	int ret = seed;
	seed = (seed * 7LL + 13) % mod;
	return ret;
}

set <pair <pair <int, int>, ll> > tab;
const ll inf = 1e18;

ll pot (ll a, int k, ll p)
{
	ll ret = 1;
	a%=p;
	while (k>0)
	{
		if (k%2==1) ret = ret * a % p;
		a = a*a % p;
		k/=2;
	}
	return ret;
}
int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n, m, vmax;
	scanf ("%d %d %d %d", &n, &m, &seed, &vmax);
	
	rep(i,1,n+1) tab.insert( { {i,i}, rnd() % vmax + 1});
	
	rep(i,0,m)
	{
		int op = rnd() % 4 + 1;
		int l = rnd() % n +1;
		int r = rnd() % n +1;
		
		if (l>r) swap(l,r);
		int x, y;
		if (op==3) x = rnd() % (r - l +1) + 1;
		else x = rnd() % vmax + 1;
		
		if (op==4) y = rnd() % vmax +1;
		
		debug ("\nmy operation %d: [%d %d] %d\n", op, l, r, x);
		
		auto it = tab.upper_bound( {{l,r}, 0});
		
		if (it==tab.end() || it->fi.fi >l) it--; //if zaczynasz sie w l - musisz zostac
		
		
		debug ("found ([%d %d] - %lld)\n", it->fi.fi, it->fi.se, it->se);
		assert(it->fi.fi <= l && it->fi.se >= l);
		
		
		vector <pair <pair <int,int>, ll> > add, erase;
		
		if (it->fi.fi < l && op <=2)
		{
			add.pb({ {it->fi.fi, l-1}, it->se});
		}
		
		if (op==1)
		{
			while (l <= r)
			{
				int right = min(it->fi.se, r);
				
				erase.pb(*it);
				add.pb({ {l, right}, it->se + x});
				
				l = right+1;
				
				if (it->fi.se > r)
				{
					add.pb({ {r+1, it->fi.se}, it->se});
				}
				it++;
			}
		}
		if (op==2)
		{
			add.pb({ {l, r}, x});
			while (it !=tab.end() && it->fi.fi <= r)
			{
				erase.pb(*it);
				if (it->fi.se > r)
				{
					add.pb({ {r+1, it->fi.se}, it->se});
				}
				it++;
			}
		}
		if (op==3)
		{
			vector <pair <ll, int> > rob;
			while (it!=tab.end() && it->fi.fi <=r)
			{
				int left = max(l, it->fi.fi);
				int right = min(r, it->fi.se);
				
				rob.pb({ it->se, right - left +1});
				it++;
			}
			
			sort(rob.begin(), rob.end());
			
			for (auto p: rob)
			{
				x-=p.se;
				if (x<=0) 
				{
					printf ("%lld\n", p.fi);
					break;
				} 
			}
		}
		if (op==4)
		{
			ll suma = 0LL;
			
			while (it!=tab.end() && it->fi.fi <=r)
			{
				int left = max(l, it->fi.fi);
				int right = min(r, it->fi.se);
				
				suma += ll(right - left +1) * pot(it->se, x, y) % ll(y);
				it++;
			}
			
			printf ("%lld\n", suma % y);
		}
		
		for (auto p: erase) tab.erase(p);
		for (auto p: add) tab.insert(p);
		
		/*
		debug ("after the query: ");
		for (auto p: tab) debug ("([%d %d] -> %lld) ", p.fi.fi, p.fi.se, p.se);
		debug ("\n");
		*/
	}
}