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
		int n;
		scanf ("%d", &n);
		vector <int> A(n), B(n);
		for (int &a: A) scanf ("%d", &a);
		for (int &b: B) scanf ("%d", &b);
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		
		bool ok = true;
		
		int cnt = 0;
		rep(i,0,n) {
			if (A[i] == B[i]) {
			
			} else if (A[i] + 1 == B[i]) {
				cnt++;
			} else {
				ok = false;
			}
		}
		
		if (ok) printf ("YES\n");
		else printf ("NO\n");
	}
}