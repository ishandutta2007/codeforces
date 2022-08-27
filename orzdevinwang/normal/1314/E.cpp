#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int mod = 998244353, N = 2077;
int n, k, dp[N];
int h[N], z[N];
bool check(vi S) {
	int m = sz(S);
	L(i, 0, m - 1) h[i + 1] = S[i];
	L(t, 1, k - 1) {
		reverse(h + 1, h + m + 1);
		int rm = 0;
		L(i, 1, m) {
			L(j, 1, h[i]) {
				z[++rm] = i;
				if(rm > n) return false; 
			}
		}
		m = rm;
		L(i, 1, m) h[i] = z[i];
	}
	int sum = 0;
	L(i, 1, m) sum += h[i];
	return sum <= n;
}
int cnt = 0;
vi now;
void DFS (vi S) {
	cnt += 1;
	for (int j = S[sz(S) - 1]; ; j++) {
		vi T = S;
		T.push_back(j);
		if(!check(T)) break;
		DFS(T);
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if(k > 8) return cout << "1\n", 0; 
	if(k <= 2) {
		dp[0] = 1;
		L(i, 1, n) {
			ll w = 1;
			L(j, i, i + k - 1) w *= j;
			L(j, 1, k) w /= j;
			if (w > n) break ;
			L(j, w, n) (dp[j] += dp[j - w]) %= mod;
		}
		int ret = 0;
		L(i, 1, n) (ret += dp[i]) %= mod;
		cout << ret << '\n';
		return 0;
	}
	L(i, 1, n) {
		if(!check(vi{i})) 
			break;
		DFS(vi{i});
	}
	cout << cnt << '\n';
	return 0;
}