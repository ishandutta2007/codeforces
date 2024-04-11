#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 3e5 + 7;
int n, s, ns;
int cnt[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	L(i, 1, n) {
		int k;
		cin >> k;
		if(i == s) {
			if(k != 0) ns ++;
		}
		else cnt[k] ++;
	}
	int sum = 0, t = 0, mx = 1e9 + 7;
	ns += cnt[0];
	L(i, 0, n) {
		if(cnt[i]) sum += cnt[i];
		else if(i) ++t;
		mx = min(mx, max(n - 1 - sum, t - cnt[0]));
	}
	mx = max(mx, 0);
	cout << mx + ns << "\n";
	return 0;
}