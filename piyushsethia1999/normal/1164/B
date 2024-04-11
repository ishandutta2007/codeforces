#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
    vector<int> b(m); for (int o = 0; o < m; o++) { cin >> b[o]; }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n == 1) {
    	int su = 0;
    	bool flag = false;
    	for (int i = 0; i < m; ++i) {
    		if (b[i] < a[0]) flag = true; 
    		su += b[i];
    	}
    	if (flag) {
    		cout << -1;
    	} else {
    		cout << su;
    	}
    } else if(m == 1) {

    	int su = 0;
    	bool flag = false;
    	for (int i = 0; i < n; ++i) {
    		if (a[i] > b[0]) flag = true; 
    		su += a[i];
    	}
    	if (flag) {
    		cout << -1;
    	} else {
    		cout << su;
    	}
    } else { 
    	sort(a.rbegin(), a.rend());
    	int su = 0;
    	int j = 0;
    	if (b[0] < a[0]) {
    		cout << -1;
    		exit(0);
    	} 
    	int cn = 0;
    	bool g = false;
	    for (int i = m - 1; i >= 0; --i) {
	    	while (i < m && j < n && a[j] > b[i]) {
	    		j++;
	    		cn = 0;
	    	} 
	    	if (a[j] == b[i]) cn = 0; 
	    	cn++;
	    	if (cn == m) {
	    		j++;
	    		if (j >= n || a[j] > b[i]) {
	    			g = true;
	    			break;
	    		} 
	    	}
	    		su += (b[i] - a[j]);
	    	
	    }
	    for (int i = 0; i < n; ++i) {
	    	su += (a[i] * m);
	    }
	    if (g) {
	    	cout << -1;
	    }else {
	    cout << su << "\n";

	    }
    }
}