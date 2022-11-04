#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;


struct Move {
	int i, j, x;
};


 
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

    	vector<int> arr(n + 1);
    	int sum = 0;
    	for(i = 1; i <= n; i++) {
    		cin >> arr[i];
    		sum += arr[i];
    	}

    	if(sum % n) {
    		cout << -1 << "\n";
    		continue;
    	}

    	vector<Move> sol;
    	int avg = sum / n;
    	for(i = 2; i <= n; i++) {
    		sol.push_back({1, i, (i - arr[i] % i) % i});
    		sol.push_back({i, 1, (arr[i] + i - 1) / i});
    	}
    	for(i = 2; i <= n; i++) {
    		sol.push_back({1, i, avg});
    	}

    	cout << (int)sol.size() << "\n";
    	for(auto it : sol) {
    		cout << it.i << " " << it.j << " " << it.x << "\n";
    	}

    }
 
    return 0;
}