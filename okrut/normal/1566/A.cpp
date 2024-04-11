#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n, s;
		scanf ("%d %d", &n, &s);
		
		int m = n - ((n+1)/2 - 1);
		printf ("%d\n", s / m);
	}
}