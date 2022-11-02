#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
 
#define int long long
#define ull long long
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

const int inf = 1e9 + 7;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	int n;
    	string s;
    	cin >> n >> s;
    	vector<int> p1(n, 1), p2(n, 1), p(n);
    	for(int i = 1;i < n;i++) {
    		if (s[i] != s[i - 1]) p1[i] = p1[i - 1] + 1;
    	}
    	for(int i = n - 2;i >= 0;i--) 
    		if (s[i] != s[i + 1]) p2[i] = p2[i + 1] + 1;

    	for(int i = 0;i < n;i++) {
    		if (s[i] == 'L') p[i] = p1[i];
    		else p[i] = p2[i];
    	}

    	for(int i = 0;i <= n;i++) {
    		int res = 1;
    		if (i > 0 && s[i - 1] == 'L') res += p[i - 1];
    		if (i < n && s[i] == 'R') res += p[i];
    		cout << res << " ";
    	}
    	cout << endl;
    }
}