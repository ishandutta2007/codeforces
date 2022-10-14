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
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n, k;
		scanf ("%d %d", &n, &k);
		
		if (k != n-1) {
			
			if (k == 0) {
				rep(i,0,n/2) {
					printf("%d %d\n", i, (n-1)^i);
				}
			} else {
				printf ("%d %d\n%d %d\n", (n-1) ^ k, 0, k, n-1);
				
				rep(i,1,n/2) if (i != k and i != ((n-1)^k)) {
					printf("%d %d\n", i, (n-1)^i);
				}
			}
		} else {
			if (n == 4) {
				printf ("-1\n");
			} else {
				
				printf ("%d %d\n%d %d\n%d %d\n%d %d\n", k, k-1, 1, 3, k-3, 0, 2, k-2);
				
				rep(i,4,n/2) {
					printf ("%d %d\n", i, (n-1) ^ i);
				}
			}
		}
		
	}
}