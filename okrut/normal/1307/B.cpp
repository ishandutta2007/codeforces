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


int main ()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n, x;
		scanf ("%d %d", &n, &x);
		vector <int> tab(n);
		for (int &a: tab) scanf ("%d", &a);
		sort(tab.begin(), tab.end());
		bool ok = false;
		for (int a: tab)
		{
			if (a==x) 
			{
				printf ("1\n");
				ok = true;
				break;
			}
		}
		if (ok) continue;
		
		int b = tab.back();
		int res = (x+b-1)/b;
		if (res==1) res++;
		
		printf ("%d\n", res);
	}
}