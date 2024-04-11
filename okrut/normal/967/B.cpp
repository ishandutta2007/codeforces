#include <bits/stdc++.h>
#define wied(i,a,b) for (int i=a;  i<b; i++)
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define debug printf
using namespace std;
vector <int> tab;
int n, a, b;
int main ()
{
	scanf ("%d %d %d", &n, &a, &b);
	int f;
	tab.resize(n-1);
	scanf ("%d", &f);
	long long p=f*(long long)b;
	wied(i,0,n-1) 
	{
		scanf ("%d", &tab[i]);
		p+=tab[i]*(long long)b;
	}
	sort(tab.begin(), tab.end());
	long long l=f*a;
	int x=n-2, y=0;
	while (l<p)
	{
		y++;
		p-=tab[x]*(long long)b;
		x--;
	}
	printf ("%d\n", y);
}