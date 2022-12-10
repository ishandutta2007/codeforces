//sobskdrbhvk
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

const int maxn = 2000 + 85 - 80;
const LL Mod = 1000 * 1000 * 1000 + 7;
int dp[maxn][maxn];
int tmp[maxn];
int n, k;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k
		>> s;
	for(auto &c : s) c -= 'a';
	dp[sz(s)][0] = 1;
	for(int i = sz(s) - 1; i >= 0; --i){
		dp[i][0] = 1;
		for(int j = 0; j <= k; ++j){
			tmp[j] = (tmp[j] + 1LL * s[i] * dp[i + 1][j]) % Mod;
			dp[i][j] += tmp[j];
			if(dp[i][j] >= Mod) dp[i][j] -= Mod;
			int ptr1 = i - 1,
				ptr2 = sz(s) - 2;
			while(ptr1 + 1 < sz(s) and (ptr1 - i + 2) * (sz(s) - ptr1 - 1) <= j){
				dp[i][j] = (dp[i][j] + 1LL * (25 - s[ptr1 + 1]) * dp[ptr1 + 2][j - (ptr1 - i + 2) * (sz(s) - ptr1 - 1)]) % Mod;
				++ptr1;
			}
			swap(ptr1, ptr2);
			while(ptr1 > ptr2 and (ptr1 - i + 2) * (sz(s) - ptr1 - 1) <= j){
				dp[i][j] = (dp[i][j] + 1LL * (25 - s[ptr1 + 1]) * dp[ptr1 + 2][j - (ptr1 - i + 2) * (sz(s) - ptr1 - 1)]) % Mod;
				--ptr1;
			}
		}
	}
	cout << (dp[0][k]+Mod)%Mod << '\n';
	return 0;
}