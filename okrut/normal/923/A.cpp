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
typedef long double ld;

const int M = 1e6+10;
bitset <M> on;
vector <int> dziel[M];
int main ()
{
	//ios_base::sync_with_stdio(false);
	vector <int> primes;
	
	on.set();
	rep(i,2,M) if (on[i])
	{
		primes.pb(i);
		int x = i+i;
		while (x<M)
		{
			dziel[x].pb(i);
			on[x] = 0;
			x+=i;
		}
	}
	
	int x;
	scanf ("%d", &x);
	
	int res = x;
	
	for (int p: primes) if (x%p==0 && x>p)
	{
		int py = x/p -1;
		int lewy = py * p + 1;
		int prawy = x;
		rep(x1,lewy,prawy+1) if (!on[x1])
		{
			int pcurr = dziel[x1].back();
			int curr = x1 - pcurr + 1;
			res = min(res, curr);
		}
	}
	printf ("%d\n", res);
}