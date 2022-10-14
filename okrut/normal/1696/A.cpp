#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n, z;
		scanf ("%d %d", &n, &z);
		int best = 0;
		rep(i,0,n) {
			int a;
			scanf ("%d", &a);
			best = max(best, a | z);
		}
		printf ("%d\n", best);
	}
}