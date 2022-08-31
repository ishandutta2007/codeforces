#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3e5 + 7; 
int n, s[N], r[N], w[N], cnt[N][2];
ll a[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
//	L(i, 1, n) a[i] = 3;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) r[i] = __builtin_popcountll(a[i]);
	cnt[0][0] += 1;
	ll ns = 0;
	L(i, 1, n) {
		int sum = r[i], mx = r[i];
		s[i] = s[i - 1] + r[i];
		R(j, i - 1, max(i - 63, 1)) {
			sum += r[j], mx = max(mx, r[j]);
			if(sum >= mx * 2 && sum % 2 == 0) ns += 1; 
		}
		cnt[i][0] = cnt[i - 1][0], cnt[i][1] = cnt[i - 1][1];
		cnt[i][s[i] & 1] += 1;
		if(i >= 65) ns += cnt[i - 65][s[i] & 1];
	}
	cout << ns << '\n';
	return 0;
}