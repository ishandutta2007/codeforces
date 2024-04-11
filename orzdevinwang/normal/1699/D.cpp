#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define sz(a) ((int) (a).size()) 
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 5007;
int n, a[N], cnt[N], dp[N];
void Main() {
	cin >> n ;
	L(i, 1, n) cin >> a[i];
	a[0] = a[n + 1] = 0;
	me(dp, -0x3f); 
	dp[0] = 0;
	L(i, 1, n + 1) {
		me(cnt, 0);
		int mx = 0;
		L(j, i - 1, n) {
			if(j != i - 1) cnt[a[j]] += 1, mx = max(mx, cnt[a[j]]);
			if(((j - i) & 1) && mx <= (j - i + 1) / 2) {
				if(!a[i - 1] || !a[j + 1] || a[i - 1] == a[j + 1]) 
					dp[j + 1] = max(dp[j + 1], dp[i - 1] + 1);
			}
		}
	}
	cout << dp[n + 1] - 1 << '\n';
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}