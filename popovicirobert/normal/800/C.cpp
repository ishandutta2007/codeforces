#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;


inline int lgput(int a, int b, int md) {
	int ans = 1;
	while(b > 0) {
		if(b & 1) ans = (1LL * ans * a) % md;
		b >>= 1;
		a = (1LL * a * a) % md;
	}
	return ans;
}


int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector<int> cnt(m + 1), gcds(m + 1);
    int phi = 0;
    for(i = 0; i <= m; i++) {
    	gcds[i] = __gcd(i, m);
    	if(gcds[i] == 1) {
    		phi++;
    	}
    }
    vector<set<int>> vals(m + 1);
    for(i = 0; i < m; i++) {
    	cnt[gcds[i]]++;
    	vals[gcds[i]].insert(i);
    }

    for(i = 1; i <= n; i++) {
    	int x;
    	cin >> x;
    	cnt[gcds[x]]--;
    	vals[gcds[x]].erase(x);
    }

    vector<int> dp(m + 1), from(m + 1, 0);
    for(i = m; i >= 1; i--) {
    	dp[i] = cnt[i];
    	for(j = 2 * i; j <= m; j += i) {
    		if(dp[i] < dp[j] + cnt[i]) {
    			dp[i] = dp[j] + cnt[i];
    			from[i] = j;
    		}
    	}
    }

    int mx = -1, nod = -1;
    for(i = 0; i <= m; i++) {
    	if(mx < dp[i]) {
    		mx = dp[i];
    		nod = i;
    	}
    }

    auto get = [&](int a, int b) {
    	assert(gcds[b] % gcds[a] == 0);
    	int ans = lgput(a / gcds[a], phi - 1, m);
    	ans = (1LL * ans * (b / gcds[a])) % m;
    	return ans;
    };

    vector<int> sol;
    int last = 1;
    while(nod != 0) {
    	for(auto it : vals[nod]) {
    		sol.push_back(get(last, it));
    		last = it;
    		//cerr << last << " ";
    	}
    	nod = from[nod];
    }

    assert((int)sol.size() == mx);
    cout << sol.size() << "\n";

    //cerr << "\n";

    int prd = 1;
    for(auto it : sol) {
    	cout << it << " ";

    	//prd = (1LL * prd * it) % m;
    	//cerr << prd << " ";
    }

    return 0;
}