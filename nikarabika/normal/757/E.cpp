//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e6 + 10;
const LL Mod = 1e9 + 7;
int gre[maxn],
	cnt[100];
LL inv[100],
   dp[100];

LL Pow(LL x, LL y){
	LL ret = 1,
	   an = x;
	while(y){
		if(y&1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y >>= 1;
	}
	return ret;
}

int C(int n, int r){
	LL ret = 1;
	for(int i = 0; i < r; i++)
		ret = (((ret * (n - i)) % Mod) * inv[r - i]) % Mod;
	return ret;
}

void solve(void){
	int n, r;
	cin >> r >> n;
	if(n == 1){
		cout << 1 << '\n';
		return;
	}
	int sz = 0;
	while(n != 1){
		cnt[sz] = 0;
		int tmp = gre[n];
		while(n % tmp == 0)
			n /= tmp, cnt[sz]++;
		sz++;
	}
	if(r == 0){
		LL ret = 1;
		for(int i = 0; i < sz; i++)
			ret = (ret * 2) % Mod;
		cout << ret << '\n';
		return;
	}
	memset(dp, 0, sz * 8 + 16);
	dp[0] = 1;
	for(int i = 0; i < sz; i++){
		dp[i] %= Mod;
		dp[i + 1] += dp[i] * C(cnt[i] + r - 1, cnt[i]);
		dp[i + 1] += dp[i] * C(cnt[i] + r - 1, cnt[i] - 1) * 2;
	}
	dp[sz] %= Mod;
	cout << dp[sz] << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(gre, -1, sizeof gre);
	for(int i = 2; i < maxn; i++)
		if(gre[i] == -1)
			for(int j = i; j < maxn; j+=i)
				gre[j] = i;
	for(int i = 1; i < 50; i++)
		inv[i] = Pow(i, Mod - 2);
	int q;
	cin >> q;
	while(q--)
		solve();
	return 0;
}