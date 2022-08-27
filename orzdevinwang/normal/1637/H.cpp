#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1 << 20;

int n, a[N];

template < int N > struct fenwt {
	using F = long long ;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= N; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
} ;

fenwt < N > A;

ll ns[N], f[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	
	ns[0] = 0;
	L(i, 1, n) f[i] = i - 1 - (a[i] - 1) * 2; 
	
	R(i, n, 1) ns[0] += A.query(a[i]),  A.add(a[i], 1); 
	L(i, 1, n) A.add(a[i], -1);
	
	sort(f + 1, f + n + 1), reverse(f + 1, f + n + 1);
	L(i, 1, n) 
		ns[i] = ns[i - 1] - (i - 1) - f[i];
	L(i, 0, n) 
		cout << ns[i] << ' ';
	cout << '\n';
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	
	int t;
	cin >> t;
	while (t--) Main ();
	
	return 0;
}