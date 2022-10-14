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


int main ()
{
	int n;
	scanf ("%d", &n);
	ll sum = ll(2*n+1) * ll(n); //to jest suma
	if (sum%2==0) 
	{
		printf ("NO\n");
	}
	else 
	{
		printf ("YES\n");
		vector <int> res(n*2, 0);
		rep(i,0,n)
		{
			if (i%2==0)
			{
				res[i] = i*2+1;
				res[n+i] = i*2+2;
			}
			else
			{
				res[i] = i*2+2;
				res[n+i] = i*2+1;
			}
		}
		for (int x: res) printf ("%d ", x);
		printf ("\n");
	}
}