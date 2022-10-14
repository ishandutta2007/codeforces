#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	
	rep(q,0,t) {
		int n;
		scanf ("%d", &n);
		vector <int> A(n), B(n), C(n);
		for (int &a: A) scanf ("%d", &a);
		for (int &b: B) scanf ("%d", &b);
		rep(i,0,n) C[i] = B[i] - A[i];
		
		int sum = 0;
		for (int c: C) sum += c;
		
		if (sum != 0) {
			printf ("-1\n");
			continue;
		}
		
		int minus = 0, plus = 0;
		vector <pair <int, int> > ans;
		
		while (minus < n && C[minus] >= 0) minus++;
		while (plus < n && C[plus] <= 0) plus++;
		
		while (minus < n && plus < n) {
			
			ans.pb({minus, plus});
			C[minus]++;
			C[plus]--;
			
			while (minus < n && C[minus] >= 0) minus++;
			while (plus < n && C[plus] <= 0) plus++;
		}
		
		printf ("%d\n", (int)ans.size());
		for (auto p: ans) printf ("%d %d\n", p.fi +1 , p.se + 1);
		
	}
}