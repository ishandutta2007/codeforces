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


const int N = 1e6+10;
int ile[N];

int main ()
{
	int n;
	scanf ("%d", &n);
	vector <vector <int> > tab;
	rep(i,0,n)
	{
		int l;
		scanf ("%d", &l);
		vector <int> wek(l);
		int old = N;
		bool has = false;
		for (int &x: wek)
		{
			scanf ("%d", &x);
			if (x > old) has = true;
			old = x;
		}
		
		if (!has) 
		{
			tab.pb(wek);
			ile[wek.back()]++;
		}
	}
	
	ll zle = 0LL;
	for (int i = N-2; i>=0; i--)
	{
		ile[i]+=ile[i+1];
	}
	
	for (auto wek: tab)
	{
		zle += ll(ile[wek[0]]);
	}
	
	printf ("%lld\n", ll(n) * ll(n) - zle);
}