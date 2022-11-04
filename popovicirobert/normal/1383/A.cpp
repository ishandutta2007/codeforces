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
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n, i;
    	string a, b;
    	cin >> n >> a >> b;

    	bool impossible = false;
    	for(i = 0; i < n; i++) {
    		if(a[i] > b[i]) {
    			impossible = true;
    		}
    	}
    	if(impossible) {
    		cout << -1 << "\n";
    		continue;
    	}

    	int answer = 0;
    	bool found = true;
    	while(found) {
    		found = false;

    		char mnA = 'z', mnB = 'z';
    		for(i = 0; i < n; i++) {
    			if(a[i] != b[i]) {
    				found = true;
    			}
    			if(a[i] != b[i]) {
    				if(a[i] < mnA || (a[i] == mnA && b[i] < mnB)) {
    					mnA = a[i];
    					mnB = b[i];
    				}
    			}
    		}

    		answer++;
    		for(i = 0; i < n; i++) {
    			if(a[i] == mnA && a[i] != b[i]) {
    				a[i] = mnB;
    			}
    		}
    	}

    	cout << answer - 1 << "\n";
    }

    return 0;
}