#include <bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

int cnt(vector <int> V)
{
    int ret = 0;
    for (int v: V) ret += v;
    return ret;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
	    int n; scanf ("%d", &n);
	    vector <int> A(n), B(n);
	    for (int &a: A) scanf ("%d", &a);
	    for (int &b: B) scanf ("%d", &b);
	    
	    int dif = 0;
	    rep(i,0,n) dif += (A[i] != B[i]);
	    
	    int ans = min(dif, abs(cnt(A) - cnt(B)) + 1);
	    printf ("%d\n", ans);
	}
}