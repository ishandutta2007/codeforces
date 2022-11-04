#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);	
	
    int n;
    cin >> n;

    vector<int> p(n + 2);
    vector<int> l(n + 1), r(n + 2);

    for (int i = 1; i <= n; i++) {
    	cin >> p[i];
    	if (p[i] > p[i - 1]) {
    		l[i] = l[i - 1] + 1;
    	} else {
    		l[i] = 1;
    	}
    }

    vector<int> pref(n + 1), suff(n + 2);
    for (int i = n; i >= 1; i--) {
    	if (p[i] > p[i + 1]) {
    		r[i] = r[i + 1] + 1;
    	} else {
    		r[i] = 1;
    	}
    }

    int len = 0;
    for (int i = 1; i <= n; i++) {
    	l[i]--;
    	if (p[i] < p[i - 1]) {
    		len++;
    	} else {
    		len = 1;
    	}
    	pref[i] = max(pref[i - 1], max(l[i], len - 1));
    }

    len = 0;
    for (int i = n; i >= 1; i--) {
    	r[i]--;
    	if (p[i] < p[i + 1]) {
    		len++;
    	} else {
    		len = 1;
    	}
    	suff[i] = max(suff[i + 1], max(r[i], len - 1));
    }

    int ans = 0;
    for (int x = 1; x <= n; x++) {
    	int mx = max(pref[min(x - 1, x - l[x])], suff[max(x + 1, x + r[x])]);

    	//cerr << mx << " " << l[x] << " " << r[x] << "\n";

    	if (mx >= max(l[x], r[x])) {
    		continue;
    	}

    	//cerr << x << " " << l[x] << " " << r[x] << "\n";

    	int mn = min(l[x], r[x]);
    	mx = max(l[x], r[x]);

    	if (mx - (mx % 2 == 0) >= mn) {
    		continue;
    	}

    	cerr << x;
    	
    	ans++;
	}

	cout << ans;

    return 0;
}