#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
vector <int> tab;

int n, m, k;
int main ()
{
	int a, b, c;
	cin>>a >>b >>c >>n;
	if ((min(a,b)<c) || (a+b-c>=n))
	{
		printf ("-1\n");
		return 0;
	}
	printf ("%d\n", n-(a+b-c));
	return 0;
}