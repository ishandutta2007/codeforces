#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int p2[1000005];
string S;

int main() {
	cin >> S;
	int cur = 1;
	p2[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		cur *= 2;
		cur %= MOD;
		p2[i] = cur;
	}
	int ans = 0;
	cur = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'a') {
			cur++;
			ans++;
			ans %= MOD;
		}
		else {
			ans += p2[cur];
			ans %= MOD;
		}
	}
	ans -= S.length();
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	printf("%d\n", ans);
	
}