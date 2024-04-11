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

const int inf = 1e5 + 32123;

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //cout.precision(3);

    int n, m;
    cin >> n >> m;

    int c = 0;
    vector<int> a(n), b(m);
    for(int i = 0;i < n;i++) {
    	cin >> a[i];
    }
    sort(all(a));
    for(int i = 1;i < n;i++) {
    	c = gcd(a[i] - a[i - 1], c);
    }

    for(int i = 0;i < m;i++)
    	cin >> b[i];
    
    for(int i = 0;i < m;i++) {
    	cout << gcd(c, b[i] + a[0]) << " ";
    }
}