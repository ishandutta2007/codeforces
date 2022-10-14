#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

bool ok (int br, int a, int b)
{
	int as = (a+b+1)/2, bs = (a+b)/2;
	int mini = abs(as - a);
	int maks = min(bs, a) + min(as, b);
	
	
	if (br < mini or br > maks) return false;
	return (maks & 1) == (br & 1);
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int a, b;
		scanf ("%d %d", &a, &b);
		
		vector <int> ans;
		rep(i,0,a+b+1) if (ok(i, a, b) || ok(i, b, a)) ans.pb(i);
		printf ("%d\n", (int)ans.size());
		for (int x: ans) printf ("%d ", x);
		printf ("\n");
	}
}