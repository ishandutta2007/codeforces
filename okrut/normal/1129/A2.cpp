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
vector <vector <int> > candies;
int n, m;
int main ()
{
	scanf ("%d %d", &n, &m);
	candies.resize(n);
	int a, b;
	rep(i,0,m)
	{
		scanf ("%d %d", &a, &b);
		candies[a-1].pb((b-a+n)%n);
	}
	rep(i,0,n) sort(candies[i].begin(), candies[i].end());
/*	rep(i,0,n)
	{
		debug ("stacja %d\n");
		for (int x: candies[i]) debug ("%d ", x);
		debug ("\n");
	}*/
	ll res;
	rep(s,0,n) 
	{
		res=0LL;
		rep(i,0,n) if (candies[i].size()>0) res=max(res, (ll) (i-s+n)%n+n*((int)candies[i].size()-1)+candies[i][0]);
		printf ("%lld ", res);
	}
	printf ("\n");
}