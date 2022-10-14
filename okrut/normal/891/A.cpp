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
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	vector <int> tab(n);
	for (auto &a: tab) scanf ("%d", &a);
	
	//jak najszybciej zrobic jeden ?
	
	int mini = 1e9;
	rep(st,0,n)
	{
		int g = tab[st];
		int i = st+1;
		while (i<n && g>1)
		{
			g = __gcd(g, tab[i]);
			i++;
		}
		
		if (g==1) mini = min(mini, i - st -1);
	}
	
	if (mini > n) printf ("-1\n");
	else
	{
		int niejed = 0;
		for (int a: tab) if (a>1) niejed++;
		int res;
		
		if (niejed == n) res = n + mini -1;
		else res = niejed;
		
		printf ("%d\n", res);
	}
}