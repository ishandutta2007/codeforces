#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	int sum = 0, n;
	scanf ("%d", &n);
	vector <int> tab(n);
	for (int &x: tab) scanf ("%d", &x);
	
	int k = 1;
	for (int &x: tab)
	{
		if (x%2==0) x/=2;
		else
		{
			x = (x+k)/2;
			k*=-1;
		}
	}
	for (int x: tab) printf ("%d\n", x);
}