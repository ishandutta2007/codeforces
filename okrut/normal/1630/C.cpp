#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+1;
int RM[N], A[N];

int main()
{
	//ios_base::sync_with_stdio(false);
	
	int n;
	scanf ("%d", &n);
	rep(i,0,n) scanf ("%d", &A[i]);
	
	rep(i,0,n) {
		RM[A[i]] = i;
	}
	
	int res = 0;
	
	rep(left,0,n) {
		if (RM[A[left]] == left)
			continue;
		
		int l = left;
		int r = RM[A[left]];
		while (r > l + 1) {
			
			int mx = 0;
			rep(i,l+1,r) mx = max(mx, RM[A[i]]);
			
			res += r - l - 1;
			
			//debug ("[%d %d] -> %d\n", l, r, r - l - 1);
			
			l = r;
			r = mx;
		}
		
		left = r;
	}
	
	printf ("%d\n", res);
}