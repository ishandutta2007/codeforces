#include <bits/stdc++.h>
using namespace std;

int N;
long long a[1000005], b[1000005];
multiset<long long> M;
set<int> S;

int main() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	for (int i = 0; i < N; i++) scanf("%d", &b[i]);
	for (int i = 1; i < N; i++) a[i] += a[i - 1];
	S.insert(-1);
	S.insert(N);
	M.insert(a[N - 1]);
	for (int i = 0; i < N; i++) {
		int pos = b[i] - 1;
		int r = *S.upper_bound(pos);
		int l = *(--S.upper_bound(pos));
		S.insert(pos);
		l++;
		r--;
		long long prevval = a[r] - ((l == 0) ? 0 : a[l - 1]);
		long long newval_l = ((pos == 0) ? 0 : a[pos - 1]) - ((l == 0) ? 0 : a[l - 1]);
		long long newval_r = a[r] - a[pos];
		M.erase(M.find(prevval));
		M.insert(newval_l);
		M.insert(newval_r);
		printf("%lld\n", *M.rbegin());
	}
}