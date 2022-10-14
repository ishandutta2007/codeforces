#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

bool uloz (int a, int b, int c, int d, vector <int> &res)
{
	if (abs(a+c-b-d)>1) return false; 
	res.clear();
	
	if (a+c <= b+d && d>0) 
	{
		res.pb(3);
		d--;
	}
	
	if (a>0 && c-1 < d) return false;
	
	while (d>0)
	{
		res.pb(2);
		res.pb(3);
		d--;
		c--;
	}
	
	if (c>0 && b+d <= a+c)
	{
		res.pb(2);
		c--;
	}
	
	while (a+b+c+d > 0)
	{
		if (b>0)
		{
			if (!res.empty() && res.back()==3) return false;
			if (!res.empty() && res.back()==1) return false;
			res.pb(1);
			b--;
		}
		
		if (a > 0) 
		{
			res.pb(0);
			a--;
		}
		else if (c>0)
		{
			res.pb(2);
			c--;
		}
	}
	
	return true;
}

int main ()
{
	int a, b, c, d;
	scanf ("%d %d %d %d", &a, &b, &c, &d);
	vector <int> res;
	
	if (uloz(a,b,c,d, res)) printf ("YES\n");
	else if (uloz(d, c, b, a, res))
	{
		for (int &x: res) x = 3-x;
		printf ("YES\n");
	}
	else 
	{
		printf ("NO\n");
		return 0;
	}
	for (int x: res) printf ("%d ", x);
	printf ("\n");
}