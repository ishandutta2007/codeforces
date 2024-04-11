#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;

signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    while(test--) {
    	string temp;
    	int n;
    	cin >> temp >> n;
    	vector<int> res(n), b(n);
    	for(int i = 0;i < n;i++) cin >> b[i];

    	vector<int> cnt(26);
    	for(int i = 0;i < temp.size();i++) cnt[temp[i] - 'a']++;

    	int id = 25;
    	for(int it = 0;it < 50;it++) {
    		if (id == 0) break;
    		vector<int> temp;
    		for(int i = 0;i < n;i++) if (b[i] == 0) temp.emplace_back(i);
    		while(temp.size() > cnt[id]) id--;


    		for(int i : temp) {
    				res[i] = id;
    				b[i] = -inf;
    			for(int j = 0;j < n;j++) b[j] -= abs(i - j);
    		}

    		cnt[id] -= temp.size();
    		id--;
    	}

    	for(int i : res) cout << (char) (i + 'a');
    	cout << endl;
    }
}