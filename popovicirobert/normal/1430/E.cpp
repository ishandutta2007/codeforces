#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr int SIGMA = 26;

struct Fenwick {
	vector<int> aib;
	int n;

	Fenwick(int _n) : n(_n) {
		aib.resize(n + 1);
	}

	void update(int pos, int val) {
		for(int i = pos; i <= n; i += lsb(i)) {
			aib[i] += val;
		}
	}

	int query(int pos) {
		int ans = 0;
		for(int i = pos; i > 0; i -= lsb(i)) {
			ans += aib[i];
		}
		return ans;
	}
};

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> n >> str;
    vector<vector<int>> pos(SIGMA);
    for(i = 0; i < n; i++) {
    	pos[str[i] - 'a'].push_back(i);
    }

    Fenwick fen(n + 1);
    ll ans = 0;
    for(i = n - 1; i >= 0; i--) {
    	char ch = str[n - i - 1] - 'a';

    	int p = pos[ch].back();
    	pos[ch].pop_back();

    	ans +=  (p + 1 - fen.query(p + 1)) - (i + 1);
    	fen.update(p + 1, 1);
    }

    cout << -ans;

    return 0;
}