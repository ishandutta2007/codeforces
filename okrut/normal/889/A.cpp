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
 
set <int> wor;
int main ()
{
	int n;
	scanf ("%d", &n);
	int res = 1;
	rep(i,0,n)
	{
		int a;
		wor.insert(i);
		scanf ("%d", &a);
		if (wor.count(a)==1) 
		{
			wor.erase(a);
		}
		else res++;
	}
	printf ("%d\n", res);
}