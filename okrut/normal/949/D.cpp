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

vector <int> ile;
int d, b;
int calc (int n) 
{
	int ret=0;
	int r = 0;
	int zapas=0;
	int y, x=0;
	rep(i,0,n)
	{
		if (r < n * 3) r+=d;
		zapas+=ile[i];
		x = max(x, i+1);
		while (zapas < b)
		{
			if (x - i > r) break;
			
			y = min(ile[x], b - zapas);
			ile[x]-=y;
			if (ile[x]==0) x++;
			zapas+=y;
		}
		if (zapas<b) 
		{
			ret++;
		}
		else zapas-=b;
	}
	return ret;
}
int main ()
{
	int n;
	scanf ("%d %d %d", &n, &d, &b);
	ile.resize(n);
	rep(i,0,n) scanf ("%d", &ile[i]);
	
	int x1 = calc( (n+1)/2);
	
	reverse(ile.begin(), ile.end());
	
	int x2 = calc( n/2);
	
	printf ("%d\n", max(x1, x2));
	
}