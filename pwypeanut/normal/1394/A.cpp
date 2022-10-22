#include <bits/stdc++.h>
using namespace std;

int N, D, M;
vector<long long> l, m;

int main() {
	scanf("%d%d%d", &N, &D, &M);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if (x > M) m.push_back(x);
		else l.push_back(x);
	}
	sort(l.begin(), l.end(), greater<long long>());
	sort(m.begin(), m.end(), greater<long long>());
	for (int i = 1; i < m.size(); i++) m[i] += m[i - 1];
	long long lsum = 0, ans = 0;
	for (int i = 0; i <= l.size(); i++) {
		int mleft = ((N - i) + D) / (D + 1);
		long long cur = lsum + ((mleft == 0 || m.size() == 0) ? 0ll : m[min(mleft - 1, (int)m.size() - 1)]);
		ans = max(ans, cur);
		//printf("%d %d %lld %lld\n", i, mleft, lsum, cur);
		if (i < l.size()) lsum += l[i];
	}
	printf("%lld\n", ans);
}