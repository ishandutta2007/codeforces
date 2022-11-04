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
    	int n, k;
    	string str;
    	cin >> n >> k >> str;

    	vector<int> len;
    	int last = -1, ans = 0, cnt = 0;
    	for(i = 0; i < n; i++) {
    		if(str[i] == 'W') {
    			ans += 1 + (last == i - 1 && i > 0);
    			cnt++;
    			if(last != -1 && last != i - 1) {
    				len.push_back(i - last - 1);
    			}
    			last = i;
    		}
    	}

    	k = min(k, n - cnt);
    	if(last == -1) {
    		cout << max(0, 2 * k - 1) << "\n";
    		continue;
    	}

    	sort(len.begin(), len.end());
    	for(auto l : len) {
    		if(k >= l) {
    			k -= l;
    			ans += 2 * l + 1;
    		}
    	}
    	ans += 2 * k;
    	cout << ans << "\n";
    }
	
    return 0;
}