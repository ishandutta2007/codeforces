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

    	vector<int> ord(n);
    	for(i = 0; i < n; i++) {
    		cin >> ord[i];
    	}

    	queue<int> Q;
    	Q.push(0);

    	int ans = 0;
    	int i = 1;
    	while(i < n) {
    		int j = i;
    		while(j + 1 < n && ord[j] < ord[j + 1]) {
    			j++;
    		}

    		int cur = Q.front() + 1;
    		ans = max(ans, cur);
    		Q.pop();

    		while(i <= j) {
    			Q.push(cur);
    			i++;
    		}
    	}

    	cout << ans << "\n";
    }


    return 0;
}