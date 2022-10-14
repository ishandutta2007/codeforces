#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 998244353;
const lint LIM = 4000;
lint N, K;

lint fact[400005];
lint invfact[400005];
lint orig[200005];
lint fake[200005];

lint pw(lint n, lint x) {
	if (x == 1) {
		return n;
	} else if (x == 0) {
		return 1;
	}
	lint res = pw(n, x / 2);
	res %= MOD;
	res *= res;
	res %= MOD;
	if (x & 1) res *= n;
	res %= MOD;
	return res;
}

lint cmb(lint n, lint r) {
    if (r > n) return 0;
    if (r < 0) return 0;
    return (((fact[n] * invfact[n - r]) % MOD) * invfact[r]) % MOD;
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i <= 400000; i++) fact[i] = (i * fact[i - 1]) % MOD;
    invfact[400000] = pw(fact[400000], MOD - 2) % MOD;
    for (int i = 400000 - 1; i >= 0; i--) invfact[i] = ((i + 1) * invfact[i + 1]) % MOD;

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> orig[i];
    }
    for (int i = 0; i < N; i++) {
        fake[i] = orig[(i + 1) % N];
    }

    lint same = 0;
    for (int i = 0; i < N; i++) {
        if (orig[i] == fake[i]) same++;
    }
    N -= same;
    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    lint ans = 1;
    for (int i = 0; i < same; i++) {
        ans *= K;
        ans %= MOD;
    }

    lint tmp = 0;
    for (int k = 0; k <= N; k++) { // k = right answer + wrong answer
        lint cur = pw(2, k);
        if (k % 2 == 0) { // right > wrong, delete case of right == wrong
            cur = (cur - cmb(k, k / 2)) % MOD;
            if (cur < 0) cur += MOD;
        }
        cur = cur * pw(2, MOD - 2); // divide by 2, as there are 2 cases: right > wrong and right < wrong
        cur %= MOD;
        
        cur = (cur * cmb(N, k)) % MOD; // pick right and wrong answers
        cur = (cur * pw(K - 2, N - k)) % MOD; // the rest
        tmp += cur;
        tmp %= MOD;
    }
    ans *= tmp;
    ans %= MOD;
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int TESTCASE;
    // cin >> TESTCASE;
    TESTCASE = 1;
    while (TESTCASE--) {
        solve();
    }
}