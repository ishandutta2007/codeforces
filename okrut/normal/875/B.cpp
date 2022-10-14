#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

const int T = (1<<19) + 1;

int tab[T];
int main ()
{
	int n;
	scanf ("%d", &n);
	
	int last = n; //ostatnie zero
	int stan = 1;
	
	printf ("1 ");
	rep(i,0,n)
	{
		int p;
		scanf ("%d", &p);
		tab[p]=1;
		stan++;
		while (last>0 && tab[last]==1) 
		{
			last--;
			stan--;
		}
		printf ("%d ", stan);
	}
	printf ("\n");
}