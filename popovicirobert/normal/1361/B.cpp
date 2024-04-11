#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MOD = (int)1e9 + 7;
const int MOD2 = (int)1e9 + 9;
const int MOD3 = 666013;

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
   	int	t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> t;
   	while(t--) {
   		int n, p;
   		cin >> n >> p;

   		vector<int> a(n);
   		for(i = 0; i < n; i++) {
   			cin >> a[i];
   		}
   		sort(a.rbegin(), a.rend());

   		int ans = 0;
   		int ans2 = 0, ans3 = 0;
   		for(auto it : a) {
   			if(ans > 0 || ans2 > 0 || ans3 > 0) {
   				ans = (ans - lgput(p, it, MOD) + MOD) % MOD;
   				ans2 = (ans2 - lgput(p, it, MOD2) + MOD2) % MOD2;
   				ans3 = (ans3 - lgput(p, it, MOD3) + MOD3) % MOD3;
   			}
   			else {
   				ans = (ans + lgput(p, it, MOD)) % MOD;
   				ans2 = (ans2 + lgput(p, it, MOD2)) % MOD2;
   				ans3 = (ans3 + lgput(p, it, MOD3)) % MOD3;
   			}
   		}

   		cout << ans << "\n";
   	}
    
    return 0;
}