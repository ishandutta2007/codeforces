#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
 
#define FNAME ""
 
const int MAX_N = 2e6 + 5;

int l[MAX_N], r[MAX_N], col[MAX_N]; 
vi cols; 
 
void go(int v) {
	if (l[v])
		go(2 * v);
	cols.pb(col[v]);
	if (r[v])
		go(2 * v + 1);
} 
 
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
       
	int n;
	cin >> n;
	/*
	if (n == 1) {
		cout 
	}*/
	forn (i, 2 * n)
		l[i] = r[i] = 0;
	int k = 1;
	while (2 * k + 1 <= n)
		k = 2 * k + 1;
	col[1] = 1;
	forab (i, 2, k + 1) 
		col[i] = col[i / 2] ^ (1 - i % 2);
	forab (i, 1, k / 2 + 1)
		l[i] = 1, r[i] = 1;
	int cnt = k;
	for (int i = k / 2 + 2; i <= k; i++) {
		int v = i;
		while (v % 2 == 0)
			v /= 2;
		v /= 2;
		if (col[i] == col[v])
			l[i] = 1, col[2 * i] = col[i] ^ 1, cnt++;
	}
	if (cnt == n - 1) {
		int ind = k / 2 + 1;
		l[ind] = 1, col[2 * ind] = col[ind] ^ 1, cnt++;
	}
	if (cnt != n) {
		cout << "0";
		return 0;
	}
 	go(1);
 	forn (i, sz(cols) - 1)
 		if (cols[i] == cols[i + 1]) {
 			cout << "0";
 			return 0;
 		}
 	cout << "1";
    return 0;
}