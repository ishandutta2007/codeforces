#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e15;
	
int n, m, r, c;

int f(int x, int y) {
	return abs(x - r) + abs(y - c);
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //cout.precision(3);

    int t;
    cin >> t;
    while(t--) {
    	cin >> n >> m >> r >> c;

    	cout << max({f(1, 1), f(1, m), f(n, 1), f(n, m)}) << endl;
    }
}