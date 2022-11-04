#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr ll INF = 1e18;

struct Node {
	ll answer;
	ll min_dp;
	int pos;
};


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; 
    cin >> n;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> h[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> b[i];
    }

    vector<ll> dp(n + 1);
    vector<Node> stk(n);
    int sz = -1;

    for (int i = 1; i <= n; i++) {
    	Node cur = {-INF, dp[i - 1], i};
    	while (sz >= 0 && h[stk[sz].pos] > h[i]) {
    		cur.min_dp = max(cur.min_dp, stk[sz].min_dp);
    		sz--;
    	}
    	cur.answer = max(cur.answer, cur.min_dp + b[i]);
    	stk[++sz] = cur;
    	if (sz > 0) {
    		stk[sz].answer = max(stk[sz].answer, stk[sz - 1].answer);
    	}
    	dp[i] = stk[sz].answer;
    	//cerr << dp[i] << " " << cur.min_dp << "\n";
    }

    cout << dp[n];
    
    return 0;
}