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
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	sort(a.begin(), a.end());
    	ll sum = 0;
    	for(i = 0; i < n; i++) {
    		sum += a[i];
    	}
    	if(sum == 0) {
    		cout << "NO\n";
    		continue;
    	}
    	if(sum > 0) {
    		reverse(a.begin(), a.end());
    	}
    	cout << "YES\n";
    	for(auto it : a) {
    		cout << it << " ";
    	}
    	cout << "\n";
    }
	
    return 0;
}