#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;

void reverse(vector<int>& a, int id) {
	//vector<int> b = *a;
	//a[0] = 1;

	for(int i = id;i < a.size();i++) {
		a[i] = 3 - a[i];
	}
}


signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	for(int i = 0;i < n;i++) cin >> a[i];

    	vector<int> b(n);
    	for(int i = 0;i < n;i++) b[i] = 2 - i % 2;

    	if (b[n - 1] == b[0]) {
    		for(int i = 1;i < n;i++) {
    			if (a[i] == a[i - 1]) {
    				reverse(b, i);
    				break;
    			}
    		}
    	}

    	bool good = true;
    	for(int i = 0;i < n;i++) if (a[i] != a[0]) good = false;
    	if (good) for(int i = 0;i < n;i++) b[i] = 1;

    	if (b[n - 1] == b[0] && a[0] != a[n - 1]) b[n - 1] = 3;

    	int q = max(b[n - 1], 2LL);
    	if (good) q = 1;
    	cout << q << '\n';
    	for(int i : b) cout << i << " ";
    	cout << '\n';
    }
}