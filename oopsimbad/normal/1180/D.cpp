#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii; 
typedef pair<ll, ll> pll;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m; cin >> n >> m;
	for(int r = 1; 2*r <= n; r++) {
		for(int c = 1; c <= m; c++) {
			cout << r << ' ' <<  c << "\n";
			cout << n-r+1<< ' ' <<  m-c+1 << "\n";
		}
	}
	if(n % 2 == 1) {
		int r = n/2 + 1;
		for(int c = 1; 2*c <= m; c++) {
			cout << r << ' ' << c << "\n";
			cout << r << ' ' << m-c+1 << "\n";
		}
		if(m % 2 == 1) cout << n/2+1 << ' ' <<  m/2+1 << "\n";
	}
	return 0;
}