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
    int t, i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	cin >> n;
    	vector<int> arr(n);
    	for(i = 0; i < n; i++) {
    		cin >> arr[i];
    	}

    	auto check = [&](int len) -> bool {
    		unordered_map<int, int> mp;
    		deque<int> deq;

    		for(int i = 0; i < n; i++) {
    			if(deq.size() && deq.front() == i - len) {
    				deq.pop_front();
    			}

    			while(deq.size() && arr[deq.back()] >= arr[i]) {
    				deq.pop_back();
    			}
    			deq.push_back(i);

    			if(i >= len - 1)
    				mp[arr[deq.front()]]++;
    		}

    		for(int i = 1; i <= n - len + 1; i++) {
    			if(mp[i] != 1)
    				return false;
    		}
    		return true;
    	};

    	int res = n + 1;
    	for(int step = 1 << 18; step; step >>= 1) {
    		if(res - step > 1 && check(res - step)) {
    			res -= step;
    		}
    	}

    	cout << check(1);
    	for(i = 2; i <= n; i++) {
    		if(i >= res) {
    			cout << 1;
    		}
    		else {
    			cout << 0;
    		}
    	}
    	cout << "\n";
    }
   	
	
    return 0;
}