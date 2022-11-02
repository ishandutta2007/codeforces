#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;

const int MAX_N = 1e6 + 100;

int a[MAX_N], t[MAX_N];

int policz(int h, int c) {
	int x = h / c;
	int ilep = h - c * x;
	int ilem = c - ilep;
	
	cerr << h << " " << c << " " << x * x * ilem + (x + 1) * (x + 1) * ilep << endl;
	return x * x * ilem + (x + 1) * (x + 1) * ilep;
}

int foo(int i) {
	return policz(a[i], t[i]) - policz(a[i], t[i] + 1);
}

priority_queue<pair<int, int> > kol;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int baza = 0;
    for (int i = 0; i < n; i++) {
		cin >> a[i];
		t[i] = 1;
		baza += a[i] * a[i];
		kol.push({foo(i), i});
		//cout << foo(i) << " ";
	}
    
    int res = 0;
    for (int i = 0; i < k - n; i++) {
		res += kol.top().first;
		int gdzie = kol.top().second;
		cerr << gdzie << " " << kol.top().first << endl;
		kol.pop();
		t[gdzie]++;
		kol.push({foo(gdzie), gdzie});
	}
	cout << baza - res;
    
    return 0;
}/*

*/