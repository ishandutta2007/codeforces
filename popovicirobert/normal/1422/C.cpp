#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

const int MOD = (int) 1e9 + 7;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
  	cin >> str;
  	int n = (int)str.size();
  	for(auto& it : str) {
  		it -= '0';
  	}

  	vector<int> pw(n + 1, 1);
  	vector<int> sum(n + 1, 1);
  	for(int i = 1; i <= n; i++) {
  		pw[i] = (10LL * pw[i - 1]) % MOD;
  		sum[i] = (sum[i - 1] + pw[i]) % MOD;
  	}

  	int ans = 0;
  	int cur = 0;
  	for(i = 0; i + 1 < n; i++) {
  		cur = (1LL * cur * 10 + str[i]) % MOD;
  		ans = (ans + 1LL * cur * sum[n - i - 2]) % MOD;
  	}

  	cur = 0;
  	for(i = n - 1; i >= 1; i--) {
  		cur = (cur + 1LL * pw[n - i - 1] * str[i]) % MOD;
  		ans = (ans + 1LL * cur * i) % MOD;
  	}

  	cout << ans;
 	
    return 0;
}