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

map <int, int> mapa;
int main ()
{
	int q;
	scanf ("%d", &q);
	rep(i,0,q)
	{
		int a;
		scanf ("%d", &a);
		int k = a;
		int b=0, pot = 1;
		bool ok = false;
		int ile=0;
		while (a>0)
		{
			ile++;
			b+=pot;
			pot*=2;
			if (a%2==0) ok = true;
			a/=2;
		}
		
		if (ok) printf ("%d\n", b);
		else
		{
			if (k==33554431) 
			{
				printf ("1082401\n");
			}
			else if (k==16777215) printf ("5592405\n");
			else if (k==8388607) printf ("178481\n");
			else if (k==4194303) printf ("1398101\n");
			else
			{
				if (mapa.count(k)==0)
				{
					int best = 0;
					rep(i,1,k)
					{
						best= max(best, __gcd(k & i, k ^ i));
					}
					mapa[k] = best;
				}
				printf ("%d\n", mapa[k]);
			}
		}
	}
}