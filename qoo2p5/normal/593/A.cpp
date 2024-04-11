#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    vector<string> s;
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) {
    	cin >> s[i];
    }

    int ans = 0;
    for (char a = 'a'; a <= 'z'; a++) {
    	for (char b = 'a'; b <= 'z'; b++) {
    		int nans = 0;

    		for (string &p : s) {
    			bool ok = true;

    			for (char c : p) {
    				if (c != a && c != b) {
    					ok = false;
    					break;
    				}
    			}

    			if (ok) {
    				nans += sz(p);
    			}
    		}

    		ans = max(ans, nans);
    	}
    }

    cout << ans << endl;

    return 0;
}