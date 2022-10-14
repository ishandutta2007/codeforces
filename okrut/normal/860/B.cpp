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
 
map <pair <int, int>, set <int> > mapa;

void printNum (int len, int x)
{
	int b = x;
	while (b>0)
	{
		b/=10;
		len--;
	}
	if (x==0) len--;
	
	rep(i,0,len) printf ("0");
	printf ("%d\n", x);
}
int main ()
{
	int n;
	scanf ("%d", &n);
	vector <int> num(n);
	for (int &a: num) scanf ("%d", &a);
	
	int id = 0;
	for (int a: num)
	{
		id++;
		rep(i,0,9)
		{
			int len = 0;
			int b = 0;
			int x = a;
			int pot = 1;
			rep(j,i,9)
			{
				b = b + (x%10) * pot;
				x/=10;
				pot *=10;
				
				len++;
				mapa[{len, b}].insert(id);
			}
			
			a/=10;
		}
	}
	
	for (int a: num)
	{
		int best = 10;
		int number = -1;
		rep(i,0,9)
		{
			int len = 0;
			int b = 0;
			int x = a;
			int pot = 1;
			
			rep(j,i,9)
			{
				b = b + (x%10) * pot;
				x/=10;
				pot*=10;
				len++;
				
				if (a==1e8)
				{
					debug ("mamy %d %d\n", len, b);
				}
				
				if (mapa[{len, b}].size()==1)
				{
					if (a==1e8) debug ("point\n");
					if (best > len)
					{
						best = len;
						number = b;
					}
				}
			}
			
			a/=10;
		}
		printNum(best,number);
	}
}