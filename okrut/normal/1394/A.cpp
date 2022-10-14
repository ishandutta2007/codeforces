#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n, m, d;
	scanf ("%d %d %d", &n, &d, &m);
	vector <int> more, less;
	
	rep(i,0,n)
	{
		int a;
		scanf ("%d", &a);
		if (a<=m) less.pb(a);
		else more.pb(a);
	}
	sort(less.begin(), less.end());
	sort(more.begin(), more.end());
	
	reverse(more.begin(), more.end());
	
	//I will never be blocked:
	ll res = 0;
	for (int x: less) res += x;
	
	debug ("No muzzle: %lld\n", res);
	
	ll curr = res;
	int lesslost = 0, lost = 0;
	int ms = more.size();
	rep(i,1,ms+1)
	{
		curr+=more[i-1]; //I will pay here
		
		debug ("+=%lld\n", more[i-1]); 
		
		if (lost +i > n) break;
		
		while (lesslost + ms - i < lost)
		{
			debug ("-= %lld\n", less[lesslost]);
			curr-=less[lesslost];
			lesslost++;
		}
		
		debug ("check\n");
		
		res = max(res, curr);
		
		lost+=d;
	}
	
	printf ("%lld\n", res);
}