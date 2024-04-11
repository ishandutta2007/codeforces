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
	int n;
	scanf ("%d", &n);
	vector <int> tab(n);
	for (int &b: tab)
	{
		scanf ("%d", &b);
	}
	
	int x = 0;
	for (int b: tab)
	{
		int a = b+x;
		x = max(x, a);
		printf ("%d ", a);
	}
	printf ("\n");
}