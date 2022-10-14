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


int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, m;
	scanf ("%d %d", &n, &m);
	vector <int> col(m), res(m,0);
	for (int &c: col) scanf ("%d", &c);
	ll sum = 0;
	for (int c: col) sum+=ll(c);
	
	rep(i,0,m)
	{
		if (col[i] > (n-i)) 
		{
			printf("-1\n");
			return 0;
		}
	}
	
	if (m-1 + (int)col.back() > n or n > sum) 
	{
		printf ("-1\n");
		return 0;
	}
	
	int k = n; //pierwszy zamalowany
	for (int i=m-1; i>=0; i--)
	{
		int l = k-col[i];
		
		int s = max(l, i);
		k = s;
		res[i] = s+1;
	}
	for (int r: res) printf ("%d ", r);
	printf ("\n");
}