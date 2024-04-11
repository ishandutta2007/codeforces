#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;



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
    	int n, l, r;
    	cin >> n >> l >> r;
    	l--;r--;

    	if (l >= n * (n - 1)) {
    		l = 0;
    		r = 0;
    	}


    	int id1 = 1;
    	while(2 * (n - id1) <= l) {
    		l -= 2 * (n - id1);	
    		r -= 2 * (n - id1);
    		id1++;
    	}


    	vector<int> b;

    	//cout << id1 << " scan" << '\n';

    	int id2 = id1 + 1;
    	while(b.size() <= r) {
    		//cout << id1 << " " << id2 << '\n';
    		b.emplace_back(id1);
    		b.emplace_back(id2);
    		id2++;
    		if (id2 == n + 1) {
    			id1++;
    			id2 = id1 + 1;
    		}

    		if (id2 == n + 1) {
    			id1 = 1;
    			id2 = 2;
    		}
    	}

    	for(int i = l;i <= r;i++) cout << b[i] << " ";
    	cout << '\n';

    }

}