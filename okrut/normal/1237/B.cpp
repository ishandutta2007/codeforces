#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

int main ()
{
	int n;
	scanf ("%d", &n);
	vector <pair <int, int> > tab(n);
	rep(i,0,n) 
	{
		int a;
		scanf ("%d", &a);
		tab[a-1].se = i+1;
	}
	rep(i,0,n) {
		int a;
		scanf ("%d", &a);
		tab[a-1].fi = i+1;
	}
	
	sort(tab.begin(), tab.end());
	
	set <int> wor;
	rep(i,1,n+1) wor.insert(i);
	int res=0;
	for (auto p: tab)
	{
		debug ("wyjeda, ten co wjechal %d\n", p.se);
		if ( (*wor.begin()) < p.se) res++;
		
		wor.erase(p.se);
	}
	printf ("%d\n", res);
}