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

    cin >> n;

    vector<char> ch(2 * n + 1);
    vector<int> pos(n + 1), arr(2 * n + 1);
    multiset<int> mst;

    for(i = 1; i <= 2 * n; i++) {
    	cin >> ch[i];
    	if(ch[i] == '-') {
    		cin >> arr[i];
    		pos[arr[i]] = i;
    	}
    	else {
    		mst.insert(i);
    	}
    }

    for(int i = 1; i <= n; i++) {
    	auto it = mst.upper_bound(pos[i]);
    	if(it != mst.begin()) {
    		it--;
    		arr[*it] = i;
    		mst.erase(it);
    	}
    	else {
    		cout << "NO";
    		return 0;
    	}
    }

    assert(mst.empty());

    for(i = 1; i <= 2 * n; i++) {
    	if(ch[i] == '+') {
    		mst.insert(arr[i]);
    	}
    	else {
    		if(arr[i] != *mst.begin()) {
    			cout << "NO";
    			return 0;
    		}
    		mst.erase(mst.find(arr[i]));
    	}
    }
    
    cout << "YES\n";
    for(i = 1; i <= 2 * n; i++) {
    	if(ch[i] == '+') {
    		cout << arr[i] << " ";
    	}
    }

    return 0;
}