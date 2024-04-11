#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, cnt[N], ls0, ls1;
char a[N], b[N]; 
int dp[N];
void Main () {
	cin >> n; 
	cin >> (a + 1) >> (b + 1);
	ls0 = ls1 = 0;
	L(i, 1, n) {
		dp[i] = dp[i - 1];
		if(a[i] == '0') ls0 = i;
		if(a[i] == '1') ls1 = i;
		if(b[i] == '0') ls0 = i;
		if(b[i] == '1') ls1 = i;
		if(ls0 && ls1) dp[i] = max(dp[i], dp[min(ls0, ls1) - 1] + 2);
		if(ls0) dp[i] = max(dp[i], dp[ls0 - 1] + 1);
	}
	cout << dp[n] << '\n';
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}