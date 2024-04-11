#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

template<class C> void mini(C &a5, C b5) { a5 = min(a5, b5); }
template<class C> void maxi(C &a5, C b5) { a5 = max(a5, b5); }

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

const int MAX_POT = 20;

int n, m;
const int nax = 1e6;

int b[nax];
int waga[nax];

mt19937_64 rng(1231231231);

void foo() {
	string s;
	cin >> s;
	
	int mib = b[0];
	for (int i = 0; i < n; i++) {
		mini(mib, b[i]);
	}
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int pot = MAX_POT - (b[i] - mib);
		if (pot < 0) {
			waga[i] = 0;
		} else {
			waga[i] = 1 << pot;
		}
		sum += waga[i];
	}
	
	int x = rng() % sum;
	
	sum = 0;
	char ans = '0';
	for (int i = 0; i < n; i++) {
		sum += waga[i];
		if (sum > x) {
			ans = s[i];
			break;
		}
	}
	
	cout << ans << endl;
	char trueAns;
	cin >> trueAns;
	for (int i = 0; i < n; i++) {
		if (trueAns != s[i]) {
			b[i]++;
		}
	}
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
		foo();
	}
    
    return 0;
}/*

*/