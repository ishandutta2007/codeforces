#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const ll INF = 1e18;

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

  	cin >> n;
  	vector<char> col(n);
  	vector<int> x(n);
  	for(i = 0; i < n; i++) {
  		cin >> x[i] >> col[i];
  	}

  	auto solve = [&](int l, int r) {
  		ll ans = 0;
  		vector<ll> red, blue;
  		for(int i = l; i <= r; i++) {
  			if(col[i] == 'R' || (col[i] == 'G' && (i == l || i == r))) {
  				red.push_back(x[i]);
  			}
  			if(col[i] == 'B' || (col[i] == 'G' && (i == l || i == r))) {
  				blue.push_back(x[i]);
  			}
  		}
  		if(col[l] == 'G' && col[r] == 'G') {
  			int coef = 1;
  			if(red.size() > 2 || blue.size() > 2) {
  				coef = 2;
  			}
  			ans = coef * (x[r] - x[l]);
  			ll mxr = 0, mxb = 0;
  			for(int i = 0; i + 1 < (int)red.size(); i++) {
  				mxr = max(mxr, red[i + 1] - red[i]);
  			}
  			for(int i = 0; i + 1 < (int)blue.size(); i++) {
  				mxb = max(mxb, blue[i + 1] - blue[i]);
  			}
  			ans = min(ans, 3LL * (x[r] - x[l]) - mxr - mxb);
  			return ans;
  		}
  		if(red.size()) {
  			ans += red.back() - red[0];
  		}
  		if(blue.size()) {
  			ans += blue.back() - blue[0];
  		}
  		return ans;
  	};

  	ll ans = 0;
  	i = 0;
  	while(i < n) {
  		int j = i + 1;
  		while(j < n && col[j] != 'G') {
  			j++;
  		}
  		if(j < n) {
  			ans += solve(i, j);
  			//cerr << solve(i, j) << "\n";
  		}
  		else {
  			ans += solve(i, j - 1);
  		}
  		//cerr << i << " " << j << " " << ans << "\n";
  		i = j;
  	}

  	cout << ans;

    return 0;
}