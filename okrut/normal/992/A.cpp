#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
int n, t, m;
set <int> wor;
int main ()
{
	int a, b;	
	cin>>n;
	rep(i,0,n)
	{
		cin>>a;
		wor.insert(a);
	}
	wor.erase(0);
	printf ("%d\n", (int)wor.size());
	
}