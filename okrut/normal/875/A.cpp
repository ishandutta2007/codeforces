#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	int n;
	scanf ("%d", &n);
	vector <int> res;
	rep(i,0,100) //suma
	{
		int sum = 0;
		int x = n-i;
		while (x>0)
		{
			sum+=x%10;
			x/=10;
		}
		if (sum==i) res.pb(n-i);
	}
	printf ("%d\n", (int)res.size());
	reverse(res.begin(), res.end());
	for (int x: res) printf ("%d\n", x);
}