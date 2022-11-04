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





int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<int> a(n + 1);
    vector<ll> sp(n + 1);

    vector<pair<ll, int>> ord1, ord2;

    for(i = 1; i <= n; i++) {
    	cin >> a[i];
    	sp[i] = sp[i - 1] + a[i];
    	ord1.push_back({-a[i] - sp[i], i});
    	ord2.push_back({a[i] - sp[i - 1], i});
    }

    sort(ord1.begin(), ord1.end());
    sort(ord2.begin(), ord2.end());

    set<int> pos;

    i = 0;
    int ans = 0;
    for(auto it : ord2) {
    	while(i < n && ord1[i].first <= it.first) {
    		pos.insert(ord1[i].second);
    		i++;
    	}
    	if(pos.size()) {
    		auto itr = pos.begin();
    		while(itr != pos.end() && it.second - *itr > 1) {
    			int l = *itr;
    			int r = it.second;

    			if((a[l] ^ a[r]) == sp[r - 1] - sp[l]) {
    				ans++;
    			}

    			itr++;
    		}
    	}
    }

    cout << ans;

    return 0;
}