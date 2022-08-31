/*
wo bu hui jian biao da shi shu /ll 
wo hao cai a
*/
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 20), mod = 1e9 + 7 ;
int n, op[N], h[N], can[N], dp[N];
vi e[N];
void dfs (int x) {
	if(!sz(e[x])) return dp[x] = 1, void ();
	if(op[x] == 1) {
		dp[x] = 0;
		for (const int &v : e[x]) dfs (v), dp[x] += dp[v];
	}
	else {
		dp[x] = 1e9;
		for (const int &v : e[x]) dfs (v), dp[x] = min(dp[x], dp[v]);
	}
}
void calc (int x) {
	if(h[x]) return can[h[x]] = 1, void ();
	if(op[x] == 1) {
		for (const int &v : e[x]) calc (v);
	}
	else {
		for (const int &v : e[x]) if(dp[v] == dp[x]) return calc (v), void ();
	}
}
int idt, stk[N], rtp, tp;
void Main () {
	rtp = idt = tp = 0;
	cin >> n;
	while (1) {
		char ch = getchar();
		if(ch == '\n') break ;
		if(ch == '(') {
			++idt;
			if(tp) e[stk[tp]].push_back(idt);
			stk[++tp] = idt;
		}
		if(ch == ')') --tp;
		if(ch == 'S') op[stk[tp]] = 0;
		if(ch == 'P') op[stk[tp]] = 1;
		if(ch == '*') {
			++idt, h[idt] = ++rtp;
			if(tp) e[stk[tp]].push_back(idt);
		}
	}
	dfs (1), calc (1);
	cout << "REVOLTING ";
	L(i, 1, rtp) cout << (ll) can[i] * n * dp[1] << ' ';
	cout << '\n';
	L(i, 1, idt) h[i] = 0, can[i] = 0, op[i] = 0, dp[i] = 0, e[i].clear ();
}
int main () {
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}