#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e11 + 7;

struct comp {
	bool operator()(pii a, pii b) {
		if (a.second - a.first == b.second - b.first) return a.first < b.first;
		else return a.second - a.first > b.second - b.first;
	}
};


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
    	set<pii, comp> a;
    	vector<int> res(n);
    	a.emplace(0, n - 1);
    	int num = 0;
    	while(a.size()) {
    		int l = (*a.begin()).first;
    		int r = a.begin()->second;
    		a.erase(a.begin());
    		num++;
    		int mid = (l + r) / 2;
    		res[mid] = num;
    		
    		if (mid != l) a.emplace(l, mid - 1);
    		if (mid != r) a.emplace(mid + 1, r);
    	}

    	for(int i : res) cout << i << " ";
    	cout << endl;
    }
}