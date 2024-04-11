#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MOD = 998244353;


int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int	i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector<int> a(n), b(m);
    for(i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for(i = 0; i < m; i++) {
    	cin >> b[i];
    }

    int pos = n - 1;
    int ans = 1;
    for(i = m - 1; i >= 0; i--) {
    	int pos_found = -1;
    	while(pos >= 0 && a[pos] >= b[i]) {
    		if(a[pos] == b[i] && pos_found == -1) {
    			pos_found = pos;
    		}
    		pos--;
    	}
    	if(pos_found == -1) {
    		cout << 0;
    		return 0;
    	}
    	//cerr << pos << " " << pos_found << "\n";
    	if(i == 0 && pos != -1) {
    		ans = 0;
    	}
    	if(i != 0) {
    		ans = (1LL * ans * (pos_found - pos)) % MOD;
    	}
    }

    cout << ans;

    return 0;
}