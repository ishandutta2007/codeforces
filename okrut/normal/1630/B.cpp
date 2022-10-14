#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

pair <int, int> range(int n, int k, vector <int> A)
{
	sort(A.begin(), A.end());
	
	int need = (n + k + 1) / 2;
	
	pair <int, int> best = {1, n};
	
	rep(l,0,n) {
		int r = l + need - 1;
		if (r >= n) {
			break;
		}
		
		if (best.se - best.fi > A[r] - A[l]) {
			best = {A[l], A[r]};
		}
	}
	
	return best;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n, k;
		scanf ("%d %d", &n, &k);
		
		vector <int> A(n);
		
		for (int &a: A) scanf ("%d", &a);
		
		pair <int, int> R = range(n, k, A);
		
		printf ("%d %d\n", R.fi, R.se);
		
		int good = 0, bad = 0;
		printf ("%d ", 1);
		
		rep(i,0,n) {
			if (A[i] >= R.fi && A[i] <= R.se) good++;
			else bad++;
			
			if (k > 1 and good > bad) {
				printf ("%d\n%d ", i+1, i+2);
				good = bad = 0;
				k--;
			}
		}
		
		printf ("%d\n", n);
		
	}
}