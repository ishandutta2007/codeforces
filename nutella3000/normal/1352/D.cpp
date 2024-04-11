#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e11 + 7;



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
    	vector<int> a(n);
    	for(int i = 0;i < n;i++) cin >> a[i];
    	int res1 = 0, res2 = 0, res3 = 0;
    	int pr1 = 0, pr2 = 0;
    	int id1 = 0, id2 = n - 1;

    	while(id1 <= id2) {
    		res3++;
    		pr1 = 0;
    		while(pr1 <= pr2) {
    			if (id1 > id2) goto endloop;
    			res1 += a[id1];
    			pr1 += a[id1];
    			id1++;
    		}

    		if (id1 > id2) goto endloop;
    		res3++;
    		pr2 = 0;

    		while(pr2 <= pr1) {
    			if (id1 > id2) goto endloop;
    			res2 += a[id2];
    			pr2 += a[id2];
    			id2--;
    		}

    	}
    	endloop:

    	cout << res3 << " " << res1 << " " << res2 << endl;
    }
}