#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+1;
int ojce[N], stan[N]; //nadwyzka ksiazat

int krol (int a)
{
	if (ojce[a]==0) return a;
	else return (ojce[a] = krol(ojce[a]));
}

bool unia (int a, int b)
{
	int ka = krol(a), kb = krol(b);
	
	if (ka==kb)
	{
		if (stan[ka]>0) 
		{
			
			stan[ka]--;
			debug ("dolacz do %d = %d\n", ka, stan[ka]);
			return true;
		}
		else return false;
	}
	
	if (stan[ka]>0 && stan[kb]>0)
	{
		ojce[kb] = ka;
		stan[ka]+= stan[kb]-1;
		debug ("polacz %d i %d - nowy stan = %d\n", ka,kb, stan[ka]);
		return true;
	}
	
	if (stan[ka]>0)
	{
		debug ("do %d = %d\n", ka, stan[ka]);
		stan[ka]--;
		return true;
	} 
	
	if (stan[kb]>0)
	{
		debug ("do %d= %d\n", kb, stan[kb]);
		stan[kb]--;
		return true;
	}
	return false;
}

int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	rep(i,1,n+1) stan[i] = 1;
	vector <pair <int, pair <int, int> > > tab(m);
	for (auto &p: tab) scanf ("%d %d %d", &p.se.fi, &p.se.se, &p.fi);
	
	sort(tab.begin(), tab.end());
	reverse(tab.begin(), tab.end());
	int res = 0;
	for (auto p: tab) if (unia(p.se.fi, p.se.se)) 
	{
		debug ("dolaczono %d %d %d\n\n", p.fi, p.se.fi, p.se.se);
		res+=p.fi;
	}
	printf ("%d\n", res);
}