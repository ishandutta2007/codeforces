#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) ((int) a.size())
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;

const ll inf = 1e18 + 7;
int n, tot, ns[N];
ll k, f[N], g[N], hf[N], hg[N];
int rmain() {
	cin >> n >> k, --k, tot = 0;
	f[0] = hf[0] = g[0] = hg[0] = 1;
	L(i, 1, n) {
		f[i] = hg[i - 1];
		if(i > 1) g[i] = hf[i - 2] + hg[i - 2] - 1, g[i] = min(g[i], inf);
		hf[i] = hf[i - 1] + f[i], hg[i] = hg[i - 1] + g[i];
		hf[i] = min(hf[i], inf), hg[i] = min(hg[i], inf);
	}
//	L(i, 1, n) cout << f[i] << " " << g[i] << "\n";int o = (k < hg[n - 1]);
	bool tmp = true;
	while(tot < n) {
		int z = tot, len = n - z;
//		cout << "k = " << k << "\n"; 
		int o = (k < hg[len - 1]);
		if(tmp) {
			if(!o) k -= hg[len - 1];
		}
		else o = false;
//		cout << k << ", " << hg[len - 1] << "\n";
		if(o) { 
			// up
			
//			cout << " = " << hg[len - 2] << "\n";
			L(j, 1, len) if((len == j ? 0 : hg[len - j - 1]) <= k) {
//				cout << "len = " << j << "\n";
				L(t, 1, j) ns[++tot] = z + t;
				if(len != j) k -= hg[len - j - 1];
				break;
			}
			tmp = false;
//			cout << "qwq\n";
		}
		else {
//			cout << k << "\n";
			// down
			ll sum = 0;
			int cs = 0;
			L(j, 2, len + 1) {
				if(sum > k) {
					L(t, 1, j - 1) ns[++tot] = z + j - t;
					cs = j - 1;
					break;
				}
				if(j != len + 1) sum += f[len - j] + g[len - j], sum = min(sum, inf);
//				cout << "sum = " << sum << "\n";
			}
//			cout << "cs = " << cs << "\n";
			L(j, 2, cs - 1) k -= f[len - j] + g[len - j];
//			cout << "k = " << k << "\n";
			tmp = true;
		}
		if(tot == z) {
			k = -1;
			break;
		}
//		cout << tot << ", " << k << "\n";
	}
	if(k) cout << "-1\n";
	else L(i, 1, n) cout << ns[i] << " \n"[i == n];
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
//	rmain();
	return 0;
}