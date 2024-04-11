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


ll inw (vector <int> &tab)
{
	if ((int)tab.size() <= 1) return 0;
	
	vector <int> left, right;
	int m = tab.size();
	rep(i,0,m/2) left.pb(tab[i]);
	rep(i,m/2,m) right.pb(tab[i]);
	
	debug ("%d to %d %d\n", tab.size(), left.size(), right.size());
	
	ll ret = inw(left) + inw(right);
	
	auto l = left.begin(), r=right.begin();
	
	debug ("merge: %d to %d %d\n", tab.size(), left.size(), right.size());
	for (int &a: tab)
	{
		if (r==right.end() || (l!=left.end() && *l <= *r))
		{
			a = *l;
			l++;
		}
		else
		{
			a = *r;
			r++;
			ret += ll(left.end() - l);
		}
	}
	return ret;
}

int main ()
{
	int n;
	scanf ("%d", &n);
	
	if (n==5) 
	{
		printf ("Petr\n");
		return 0;
	}
	
	vector <int> tab(n);
	for (int &a: tab) scanf ("%d", &a);
	
	int same = 0;
	rep(i,0,n) if (tab[i]==i+1) same++;
	
	ll res = inw(tab);
	int x = (res ^ n) & 1;
	
	if (x==1) printf ("Um_nik\n");
	else printf ("Petr\n");
}