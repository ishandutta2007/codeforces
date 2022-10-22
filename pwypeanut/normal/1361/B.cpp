#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int T, N, P, A[1000005];
map<int, int> a, b;

int qexp(int b, int p, int m) {
	if (p == 0) return 1;
	else if (p == 1) return b % m;
	else if (p % 2 == 0) {
		long long a = qexp(b, p/2, m);
		a *= a;
		a %= m;
		return a;
	} else {
		long long a = qexp(b, p/2, m);
		a *= a;
		a %= m;
		a *= b;
		return a % m;
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &P);
		for (int i = 0; i < N; i++) scanf("%d", &A[i]);
		sort(A, A + N, greater<int>());
		
		if (P == 1) {
			printf("%d\n", N % 2);
			continue;
		}
		a.clear();
		b.clear();
		int ans = 0;
		
		for (int i = 0; i < N; i++) {
			bool a_low = 0;
			if (a.size() == 0) a_low = 1;
			else if (b.size() == 0) a_low = 0;
			else if (a.begin()->first < b.begin()->first) a_low = 1;
			else a_low = 0;
			
			if (a_low) {
				ans += qexp(P, A[i], MOD);
				ans %= MOD;
				
				if (b.find(A[i]) == b.end()) {
					while (a.find(A[i]) != a.end() && a[A[i]] == P - 1) {
						a.erase(A[i]);
						A[i]++;
					}
					if (b.find(A[i]) != b.end()) {
						b[A[i]]--;
						if (b[A[i]] == 0) b.erase(A[i]);
					}
					else a[A[i]]++;
				}
				else {
					b[A[i]]--;
					if (b[A[i]] == 0) b.erase(A[i]);
				}
				
			} else {
				ans += (MOD - qexp(P, A[i], MOD));
				ans %= MOD;
				if (a.find(A[i]) == a.end()) {
					while (b.find(A[i]) != b.end() && b[A[i]] == P - 1) {
						b.erase(A[i]);
						A[i]++;
					}
					if (a.find(A[i]) != a.end()) {
						a[A[i]]--;
						if (a[A[i]] == 0) a.erase(A[i]);
					} else b[A[i]]++;
				}
				else {
					a[A[i]]--;
					if (a[A[i]] == 0) a.erase(A[i]);
				}
			}
		}
		bool a_low = 0;
		if (a.size() == 0) a_low = 1;
		else if (b.size() == 0) a_low = 0;
		else if (a.begin()->first < b.begin()->first) a_low = 1;
		else a_low = 0;
		
		if (a_low) ans = MOD - ans;
		printf("%d\n", ans % MOD);
	}
}