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
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> a(6);
    for(i = 0; i < 6; i++) {
    	cin >> a[i];
    }

    cin >> n;
    vector<vector<int>> vals(n);
    vector<int> all;
    map<int, set<int>> ids;

    for(i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	for(int j = 0; j < 6; j++) {
    		vals[i].push_back(x - a[j]);
    		ids[x - a[j]].insert(i);
    		all.push_back(x - a[j]);
    	}
    	sort(vals[i].begin(), vals[i].end());
    }
    
    sort(all.begin(), all.end());

    multiset<int> mst;
    for(i = 0; i < n; i++) {
    	mst.insert(vals[i][0]);
    }

    vector<int> pos(n);
    int ans = *prev(mst.end()) - all[0];
    i = 0;

    while(i < (int)all.size()) {

    	if(i > 0 && all[i] != all[i - 1]) {
	    	for(auto id : ids[all[i - 1]]) {
	    		assert(vals[id][pos[id]] == all[i - 1]);
	    		mst.erase(mst.find(vals[id][pos[id]]));

	    		while(pos[id] < 6 && vals[id][pos[id]] < all[i]) {
	    			pos[id]++;
	    		}
	    		if(pos[id] == 6) {
	    			i = all.size();
	    			break;
	    		}

	    		mst.insert(vals[id][pos[id]]);
	    	}
    	}
   
    	if(i < (int)all.size()) {
	    	ans = min(ans, *prev(mst.end()) - all[i]);
	    }
    	i++;
    }

    cout << ans;
    

    return 0;
}