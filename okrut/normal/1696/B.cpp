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
		int n;
		scanf ("%d", &n);
		int prv = 0, res = 0;
		rep(i,0,n) {
		
			int a;
			scanf ("%d", &a);
			if (a == 0 && prv > 0) res++;
			
			prv = a;
		}
		if (prv > 0) res++;
		
		printf ("%d\n", min(res, 2));
	}
}