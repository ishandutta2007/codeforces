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
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
    	int n;
    	string str;
    	cin >> n >> str;

    	vector<int> lens;
    	i = 0;
    	while(i < n) {
    		int j = i;
    		while(j < n && str[j] == str[i]) {
    			j++;
    		}
    		lens.push_back(j - i);
    		i = j;
    	}

    	auto check = [&](int num) -> bool {
    		if(num > (int)lens.size()) return false;

    		int cur = 0;
    		for(int i = 0; i < num; i++) {
    			cur = min(cur + lens[i] - 1, i + 1);
    		}
    		for(int i = num; i < (int)lens.size(); i++) {
    			cur += lens[i];
    		}
    		return cur >= num - 1;
    	};

    	int res = 0;
    	for(int step = 1 << 17; step; step >>= 1) {
    		if(check(res + step)) {
    			res += step;
    		}
    	}

    	cout << res << "\n";
    }



    return 0;
}