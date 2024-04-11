#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

bool solve ()
{
	int n;
	scanf ("%d", &n);
	vector <int> A(n);
	for (auto &a: A) scanf ("%d", &a);
	
	rep(m,0,(1<< (n+n))) {
		int sum = 0;
		
		rep(i,0,n) if (m & (1<<i)) {
			if (m & (1<<(n+i))) sum -= A[i];
			else sum += A[i];
			
			if (sum == 0) return true;
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
		if (solve()) printf ("YES\n");
		else printf ("NO\n");
		
		
	}
}