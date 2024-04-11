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

vector <int> arri, dep;

int main ()
{
	int n, m, ta, tb, k;
	scanf ("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
	arri.resize(n);
	dep.resize(m);
	rep(i,0,n)
	{
		scanf ("%d", &arri[i]);
		arri[i]+=ta;
	}
	rep(i,0,m)
	{
		scanf ("%d", &dep[i]);
	}
	
	int x=0;
	int prev=0; //cost of cancelling all previous
	int czas;
	rep(i,0,m) 
	{
		while (x<n && arri[x]<=dep[i]) x++;
		prev = min(prev+1, x);
		
		debug ("disable %d-th dep  - %d\n", i, prev);
		
		if (prev<=k) 
		{
			if (i+1<m) czas = dep[i+1]+tb;
			else czas = -1;
		}
		else break;
	}
	printf ("%d\n", czas);
}