#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+10;
int A[N], n;

bool solve(vector <int> ops)
{
	int ones = 0;
		rep(p,1,n+1) {
			ones += A[p];
			if (!A[p] and !(ones & 1)) {
				
				for (int r = p-1; r > 0; r--) if (A[r]) {
					
					int l = r-1;
					while (A[l] == 0) l--;
					
					for (int i = l; i < r; i+=2) {
						ops.pb(i);
						int x = A[i] ^ A[i+1] ^ A[i+2];
						A[i] = A[i+1] = A[i+2] = x;
					}
					
					assert((int)ops.size() <= n);
				}
				
				for (int l = p+1; l < n; l++) if (A[l]) {
					int r = l+1;
					while (A[r] == 0) r++;
					
					for (int i = r; i > l; i -= 2) {
						ops.pb(i-2);
						int x = A[i] ^A[i-1] ^ A[i-2];
						A[i] = A[i-1] = A[i-2] = x;
					}
					
					assert((int)ops.size() <= n);
				}
				
				printf ("YES\n%d\n", (int)ops.size());
				for (int x: ops) printf ("%d ", x);
				if (!ops.empty()) printf ("\n");
				
				return true;
			}
		}
		
		return false;
	} 

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		scanf ("%d", &n);
		rep(i,1,n+1) scanf ("%d", &A[i]);
		
		int ones = 0;
		rep(i,1,n+1) ones += A[i];
		
		if (ones & 1) {
			printf ("NO\n");
			continue;
		}
		
		if (!solve({})) {
			
			vector <int> ops;
			rep(i,1,n-1) {
				debug ("Try %d (%d)\n", i, n);
				if (A[i] == 1 and A[i+1] == 0) {
					ops.pb(i);
					int x = A[i] ^ A[i+1] ^ A[i+2];
					A[i] = A[i+1] = A[i+2] = x;
					
					debug ("Do at %d with %d\n", i, x);
					
					if (x == 0 && solve(ops)) {
						n = 0;
						break;
					}
				}
			}
			
			if (n) printf ("NO\n");
			
		}
		
		
		
		
		
	}
}