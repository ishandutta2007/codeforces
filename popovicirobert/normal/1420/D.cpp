#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;


const int MOD = 998244353;

inline int lgput(int a, int b) {
	int ans = 1;
	while(b > 0) {
		if(b & 1) ans = (1LL * ans * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return ans;
}
 
 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    cin >> n >> k;
    vector<pair<int, int>> pts;
    for(i = 1; i <= n; i++) {
    	int l, r;
    	cin >> l >> r;
    	pts.push_back({l, 1});
    	pts.push_back({r + 1, -1});
    }

    sort(pts.begin(), pts.end());

    vector<int> fact(n + 1, 1), invfact(n + 1, 1);
    for(i = 1; i <= n; i++) {
    	fact[i] = (1LL * fact[i - 1] * i) % MOD;
    	invfact[i] = lgput(fact[i], MOD - 2);
    }

    auto comb = [&](int n, int k) -> ll {
    	if(n < k) return 0;
    	return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
    };

    int active = 0, ans = 0;
    i = 0;
    while(i < 2 * n) {
    	int j = i, cur = 0;
    	while(j < 2 * n && pts[i].first == pts[j].first) {
    		cur += (pts[j].second == 1);
    		active += pts[j].second;
    		j++;
    	}
    	//cerr << active << " " << cur << " " << comb(active, k) - comb(active - cur, k) << "\n";

    	ans = (1LL * ans + MOD + comb(active, k) - comb(active - cur, k)) % MOD;
    	i = j;
    }	

    cout << ans;

 
    return 0;
}