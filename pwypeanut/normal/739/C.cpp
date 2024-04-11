#include <bits/stdc++.h>
using namespace std;

int N, A[300005], Q, zeroes;
long long val[300005];
long long fw[300005], tv;
set<int> valleys;
multiset<int> selection;

void update(int p, int v) {
	p++;
	if (p != 1 && p != N + 1) {
		if (val[p] == 0 && val[p] + v != 0) zeroes--;
		if (val[p] != 0 && val[p] + v == 0) zeroes++;
		//printf("%lld to %lld (%d)\n", val[p], val[p] + v, zeroes);
		val[p] += v;
	} 
	for (int i = p; i <= N; i += (i & (-i))) fw[i] += v;
}

long long query(int p) {
	p++;
	long long ans = 0;
	for (int i = p; i > 0; i -= (i & (-i))) ans += fw[i];
	return ans;
}

bool check_valley(int i) {
	bool is_valley = 0;
	if (i == 0 || i == N-1) is_valley = 1;
	else if (query(i) == query(i - 1) || query(i) == query(i + 1)) is_valley = 1;
	else if (query(i) <= query(i - 1) && query(i) <= query(i + 1)) is_valley = 1;
	return is_valley;
}

void confirm_valley(int x) {
	if (x <= 0 || x >= N - 1) return;
	bool iv = check_valley(x);
	if (iv && valleys.find(x) != valleys.end()) return;
	if (!iv && valleys.find(x) == valleys.end()) return;
	if (iv) {
		// added
		valleys.insert(x);
		set<int>::iterator it = valleys.find(x);
		it++;
		int r = *it;
		it--;
		it--;
		int l = *it;
		selection.erase(selection.find(r - l));
		selection.insert(r - x);
		selection.insert(x - l);
		//printf("valley %d added\n", x);
	} else {
		set<int>::iterator it = valleys.find(x);
		it++;
		int r = *it;
		it--;
		it--;
		int l = *it;
		valleys.erase(x);
		selection.erase(selection.find(r - x));
		selection.erase(selection.find(x - l));
		selection.insert(r - l);
		//printf("valley %d removed\n", x);
	}
}

int main() {
	
	scanf("%d", &N);
	zeroes = N - 1;
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	update(0, A[0]);
	for (int i = 1; i < N; i++) update(i, A[i] - A[i - 1]);
	scanf("%d", &Q);
	if (N == 1) {
		for (int i = 0; i < Q; i++) printf("1\n");
		return 0;
	}
	for (int i = 0; i < N; i++) if (check_valley(i)) valleys.insert(i);
	for (set<int>::iterator it = valleys.begin(); it != valleys.end(); it++) {
		int l = *it;
		it++;
		if (it == valleys.end()) break;
		int r = *it;
		it--;
		//printf("valley %d\n", l);
		selection.insert(r - l);
	}
	//if (tv == 0) printf("1\n");
	//else printf("%d\n", *selection.rbegin() + 1);
	for (int i = 0; i < Q; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		update(a, c);
		update(b + 1, -c);
		confirm_valley(a - 1);
		confirm_valley(a);
		confirm_valley(b);
		confirm_valley(b + 1);
		if (zeroes == N - 1) printf("1\n");
		else printf("%d\n", *selection.rbegin() + 1);
	}
}