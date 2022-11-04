#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<bool> ciur(n + 1, 1);
    vector<int> sol;
    for(i = n; i >= 1; i--) {
    	int num = 0;
    	for(j = (n / i) * i; j >= i; j -= i) {
    		num += ciur[j];
    	}
    	j = (n / i) * i;
    	while(num > 1) {
    		if(ciur[j]) {
    			num--;
    			sol.push_back(i);
    		}
    		ciur[j] = 0;
    		j -= i;
    	}
    }
	reverse(sol.begin(), sol.end());
	for(auto it : sol) {
		cout << it << " ";
	}

    return 0;
}