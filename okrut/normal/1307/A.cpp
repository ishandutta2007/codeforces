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
		int n, d;
		scanf ("%d %d", &n, &d);
		vector <int> tab(n);
		for (int &x: tab) scanf ("%d", &x);
		
		int res = 0;
		rep(i,0,n)
		{
			while (tab[i]>0 && d>=i)
			{
				res++;
				tab[i]--;
				d-=i;
			}
		}
		printf ("%d\n", res);
	}
}