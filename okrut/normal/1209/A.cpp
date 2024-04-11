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

int tab[101];
int main ()
{
	int n, a;
	scanf ("%d", &n);
	rep(i,0,101) tab[i] = 0;
	rep(i,0,n) 
	{
		scanf ("%d", &a);
		tab[a]++;
	}
	
	int res = 0;
	rep(i,1,101)
	{
		if (tab[i]>0) 
		{
			res++;
			int x = i;
			while (x<=100)
			{
				tab[x] = 0;
				x+=i;
			}
		}
	}
	printf ("%d\n", res);
}