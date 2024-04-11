#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a, b) push_back(a, b)

int n;
int ans[110];
bool f[(int) 1e6 + 100];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    ans[0] = 0;

    for (int i = 1; i <= n; i++) {
    	char t;
    	int x;
    	cin >> t >> x;

    	ans[i] = ans[i - 1];

    	if (t == '+') {
    		f[x] = true;
    		ans[i]++;
    	} else if (t == '-') {
    		if (f[x]) {
    			f[x] = false;
    			ans[i]--;
    		} else {
    			for (int j = 0; j < i; j++) {
    				ans[j]++;
    			}
    		}
    	}
    }

    int k = 0;
    for (int i = 0; i <= n; i++) {
    	k = max(k, ans[i]);
    }

    cout << k << endl;

    return 0;
}