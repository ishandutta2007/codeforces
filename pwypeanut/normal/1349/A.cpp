#include <bits/stdc++.h>
using namespace std;

int N, A[100005];
bool notprime[200005];
vector<int> primes, count1[200005];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 2; i <= 200000; i++) {
		if (notprime[i]) continue;
		for (int j = i*2; j <= 200000; j+=i) notprime[j] = 1;
		primes.push_back(i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < primes.size(); j++) {
			if (primes[j] > sqrt(A[i])) break;
			int cnt = 0;
			while (A[i] % primes[j] == 0) {
				cnt++;
				A[i] /= primes[j];
			}
			if (cnt > 0) count1[primes[j]].push_back(cnt);
		}
		if (A[i] > 1) count1[A[i]].push_back(1);
	}
	long long ans = 1;
	for (int i = 0; i <= 200000; i++) {
		sort(count1[i].begin(), count1[i].end());
		if (count1[i].size() == 0) continue;
		if (count1[i].size() <= N - 2) continue;
		else if (count1[i].size() == N - 1) {
			if (count1[i].size() > 0) for (int j = 0; j < count1[i][0]; j++) ans *= i;
		} else {
			if (count1[i].size() > 0) for (int j = 0; j < count1[i][min(1, (int)count1[i].size() - 1)]; j++) ans *= i;
		}
		//printf("%d %d\n", i, count1[i].size());
	}
	printf("%lld\n", ans);
}