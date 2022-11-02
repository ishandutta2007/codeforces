#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
struct Mint{
	int x;
	Mint(){};
	Mint(const int& v){ x = v; }
	void operator= (const int& v) { x = v; }
	void operator= (const Mint& o) { x = o.x; }
	Mint operator+ (const Mint& o) const { Mint res; res.x = ((x + o.x) % mod + mod) % mod; return res; }
	void operator+= (const Mint& o) { x = ((x + o.x) % mod + mod) % mod; }
	friend std::ostream& operator<< (std::ostream& stream, const Mint& mint) {
        stream << mint.x;
        return stream;
    }
};

Mint dp[1000001];
Mint s[1000001];
int f[1000001];
int32_t main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			f[j]++;
		}
	}
	dp[0] = 0; s[0] = 0;
	for(int i = 1; i <= n; i++){
		dp[i] = s[i - 1] + Mint(f[i]);
		s[i] = s[i - 1] + dp[i];
	}
	cout << dp[n] << endl;
}