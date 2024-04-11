#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 2e5 + 7, O = 1e5, B = 320, mod = 998244353;
int n, a[N], b[N], cnt[N], mx;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(w, -B, B) {
		L(i, 1, n) b[i] = a[i] + w * i; 
		sort(b + 1, b + n + 1);
		int cur = 0;
		L(i, 1, n) {
			if(b[i] != b[i - 1]) cur = 0;
			cur += 1;
			mx = max(mx, cur);
		}
	}
	L(i, 1, n) {
		L(j, i + 1, min(n, i + B)) if((a[j] - a[i]) % (j - i) == 0) {
			int w = (a[j] - a[i]) / (j - i);
			cnt[w + O] += 1, mx = max(mx, cnt[w + O] + 1);
		}
		L(j, i + 1, min(n, i + B)) if((a[j] - a[i]) % (j - i) == 0) 
			cnt[(a[j] - a[i]) / (j - i) + O] = 0;
	}
	cout << n - mx << '\n';
	return 0;
}