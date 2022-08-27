#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; ++i)
using namespace std;
const int N = 1 << 21;
int n, t, cut[N], S, cnt, ret, lk, l;
char s[N];
int main() {
	for(cin >> t; t--; ) {
		cin >> (s + 1), n = strlen(s + 1), cut[n] = 1, S = 0;
		L(i, 1, n) S += s[i] - '0';
		if(!S) cout << -1 << '\n';
		else for(int o = 1; o <= N; o <<= 1) { 
			lk = o - S, ret = cnt = 0;
			L(i, 1, n - 1) {
				ret += s[i] - '0';
				if(ret && lk >= ret) lk -= ret, cut[i] = 0, ret *= 2;
				else ret = 0, cut[i] = 1, cnt += 1;
			}
			if(lk) continue ;
			cout << cnt + 1 << '\n', l = 1;
			L(i, 1, n) if(cut[i]) cout << l << ' ' << i << '\n', l = i + 1;
			break ;
		} 
	}
	return 0;
}