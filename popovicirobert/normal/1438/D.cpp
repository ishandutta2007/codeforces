#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

template<typename T>
T max(T&& a) {
	return a;
}

template<typename T, typename... Args>
T max(T&& a, Args&&... args) {
	T b = max(std::forward<Args>(args)...);
	return (a < b ? b : a);
}

template<typename T>
T min(T&& a) {
	return a;
}

template<typename T, typename... Args>
T min(T&& a, Args&&... args) {
	T b = min(std::forward<Args>(args)...);
	return (a < b ? a : b);
}


struct Move {
	int i, j, k;
};


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<Move> sol;
    for(int i = 0; i + 2 < n; i += 2) {
    	int cur = (a[i] ^ a[i + 1] ^ a[i + 2]);
    	a[i] = a[i + 1] = a[i + 2] = cur;
    	sol.push_back({i, i + 1, i + 2});
    }
    
    if(n % 2 == 0) {
    	if(a[n - 1] != a[n - 2]) {
    		cout << "NO";
    		return 0;
    	}
    	for(int i = 0; i + 1 < n - 4; i += 2) {
	    	a[i] = a[i + 1] = 0;
	    	sol.push_back({i, i + 1, n - 1});
    	}
    }
    else {
    	for(int i = 0; i + 1 < n; i += 2) {
	    	a[i] = a[i + 1] = a[n - 1];
	    	sol.push_back({i, i + 1, n - 1});
    	}
    }
    	
    cout << "YES\n" << sol.size() << "\n";
    for(auto it : sol) {
    	cout << it.i + 1 << " " << it.j + 1 << " " << it.k + 1 << "\n";
    }

    return 0;
}