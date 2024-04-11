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

    int t;
    cin >> t;
    while (t--) {	
    	int n;
	    cin >> n;

	    vector<int> arr(n);
	    set<int> alive, bad;
	    for (int i = 0; i < n; i++) {
	    	cin >> arr[i];
	    }
	    for (int i = 0; i < n; i++) {
	    	alive.insert(i);
	    	if (__gcd(arr[i], arr[(i + 1) % n]) == 1) {
	    		bad.insert(i);
	    	}
	    }

	    vector<int> sol;
	    int pos = 0;
	    while (bad.size()) {
	    	auto itr = bad.lower_bound(pos);

	    	if (itr == bad.end()) {
	    		pos = 0;
	    		continue;	
	    	}

	    	auto getNext = [&alive](int p) -> int {
	    		auto itr = alive.upper_bound(p);
		    	if (itr == alive.end()) {
		    		itr = alive.begin();
		    	}
		    	return *itr;
	    	};
	    	
	    	int p1 = *itr;
	    	bad.erase(p1);

	    	int p2 = getNext(p1);

	    	if (bad.find(p2) != bad.end()) {
	    		bad.erase(p2);
	    	}

	    	sol.push_back(p2);
	    	alive.erase(p2);

	    	if (alive.size() == 0) break;

	    	int p3 = getNext(p2);

	    	if (__gcd(arr[p1], arr[p3]) == 1) {
	    		bad.insert(p1);
	    	}

	    	pos = p3;
	    }

	    cout << sol.size() << " ";
	    for (auto it : sol) {
	    	cout << it + 1 << " ";
	    }
	    cout << "\n";
	}

    return 0;
}