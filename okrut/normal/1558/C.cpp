#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

void rot (int p, vector <int> &A, vector <int> &ans)
{
	ans.pb(p);
	rep(i,0,p/2) swap(A[i], A[p-i-1]);
}

bool ok (vector <int> A)
{
	int cnt = 0;
	for (int a: A) {
		cnt++;
		if ((cnt & 1) != (a & 1)) return false;
	}
	return true;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n;
		scanf ("%d", &n);
		vector <int> A(n), ans;
		for (int &a: A) scanf ("%d", &a);
		
		if (!ok(A)) {
			printf ("-1\n");
			continue;
		}
		
		
		while (n > 1) {
			
			int pn, pn1;
			rep(i,0,n) {
				if (A[i] == n) pn = i+1;
				if (A[i] == n-1) pn1 = i+1;
			}
			
			debug ("Situation with %d %d (%d)\n", pn, pn1, n);
			
			if (pn == n and pn1 == n-1) {
				n-=2;
				continue;
			}
			
			// jeden krok
			if (pn == 1 and pn1 == 2) {
				rot(n, A, ans);
				n-=2;
				continue;
			}
			
			// dwa kroki
			if (pn1 + 1 == pn) {
				rot(pn, A, ans);
				continue;
			}
			
			// trzy kroki
			if (pn + 1 == pn1) {
				rot(pn+2, A, ans);
				continue;
			}
			
			// cztery kroki
			if (pn < pn1 and pn == 1) {
				rot(pn1-1, A, ans);
				continue;
			}
			
			// pi krokw
			if (pn < pn1) {
				rot(pn, A, ans);
				continue;
			}
			
			if (pn > pn1) {
				rot(pn, A, ans);
				continue;
			}
		}
		
		printf ("%d\n", (int)ans.size());
		for (int a: ans) printf ("%d ", a);
		printf ("\n");
	}
}