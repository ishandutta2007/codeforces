#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
int n, m, q, all, w[N];
int k[N], d[N], Cnt[N], ans[N], A[N];
char s[N];
int mp[N];
int has() {
	int res = 0;
	L(i, 1, n) res += ((s[i] - '0') << (i - 1));
	return res;
}
vector<int> ve[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q, all = (1 << n) - 1;
	L(i, 1, n) cin >> w[i];
	L(i, 1, m) {
		cin >> (s + 1);
		mp[has()] ++;
	}
	L(i, 1, q) {
		cin >> (s + 1) >> k[i], d[i] = has();
		ve[d[i]].push_back(i);
	}
	L(i, 0, all) L(d, 0, n - 1) if(i >> d & 1) A[i] += w[d + 1];
	L(i, 0, all) {
		L(t, 0, 100) Cnt[t] = 0;
		L(j, 0, all) Cnt[A[i & j] + A[all ^ (i | j)]] += mp[j];
		L(t, 1, 100) Cnt[t] += Cnt[t - 1];
		for(int g : ve[i]) ans[g] = Cnt[k[g]];
	}
	L(i, 1, q) cout << ans[i] << endl;
	return 0;
}