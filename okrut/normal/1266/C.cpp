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

const int N = 500;
int R[N], C[N];
int main ()
{
	int r, c;
	scanf ("%d %d", &r, &c);
	
	if (r==1 && c==1) 
	{
		printf ("0\n");
		return 0;
	}
	
	if (r==1)
	{
		rep(i,0,c) C[i] = i+2;
		R[0] = 1;
	}
	else
	{
		C[0] = 1;
		rep(i,0,r) R[i] = i+2;
		rep(i,1,c) C[i] = r+i+1;
	}
	
	rep(i,0,c) debug ("%d ", C[i]);
	debug (" - ");
	rep(i,0,r) debug ("%d ", R[i]);
	debug ("\n");
	
	rep(i,0,r)
	{
		rep(j,0,c) printf ("%d ", R[i]*C[j]/__gcd(R[i], C[j]));
		printf ("\n");
	}
}