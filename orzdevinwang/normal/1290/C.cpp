#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 20;
int n, k, f[N], cnt[N], op[N];
vi S[N];
int find (int x) {
	return f[x] == x ? x : f[x] = find (f[x]);
}
int ns = 0;
int getv (int x) {
	if(x <= k) return min (cnt[find (x)], cnt[find(x + k + 1)]);
	else return min (cnt[find (x)], cnt[find(x - k - 1)]);
}
void merge (int x, int y) {
	x = find (x);
	y = find (y);
	if(x == y) return ;
	cnt[y] += cnt[x], f[x] = y;
	//cout << "GV " << cnt[find (1 + k)] << '\n';
}
char s[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> k >> (s + 1);
	L(i, 1, k * 2 + 1) f[i] = i, cnt[i] = i > k + 1;
	cnt[k + 1] = 1919810;
	L(i, 1, k) {
		int t ;
		cin >> t;
		while (t--) {
			int w;
			cin >> w;
			S[w].push_back(i);
		}
	}
	L(i, 1, n) {
		if(sz(S[i]) > 0) {
			if(sz(S[i]) == 1) S[i].push_back(0);
			int u = S[i][0], v = S[i][1];
			if(s[i] == '0') {
				if (find (u) != find (v + k + 1)) {
					ns -= getv (u), ns -= getv (v);
					merge (u, v + k + 1), merge (u + k + 1, v);	
					ns += getv (u);
				}
			}
			else {
				if (find (u) != find (v)) {
					ns -= getv (u), ns -= getv (v);
					merge (u, v), merge (u + k + 1, v + k + 1);	
					ns += getv (u);
				}
			}
		}
		cout << ns << '\n';
	}
	return 0;
}