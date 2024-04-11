#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int inv(int n) {
	return (n <= 1) ? n : (MOD - (long long)inv(MOD % n) * (MOD / n) % MOD);
}

struct Tuple
{
	int a;
	int b;
	int d;
};

Tuple mul(const Tuple& m1, const Tuple& m2) {
	Tuple m3;
	m3.a = (long long)m1.a * m2.a % MOD;
	m3.b = ((long long)m1.a * m2.b + m1.b) % MOD;
	m3.d = ((long long)m1.a * m2.d + m1.d) % MOD;
	return m3;
}

int n;
vector<int> p;
Tuple mat[2000000];

void construct(int index, int l, int r) {
	if (l == r) {
		Tuple m;
		m.a = p[l];
		m.b = 1;
		m.d = (1 - p[l] + MOD) % MOD;
		mat[index] = m;
	}
	else {
		int m = (l + r) / 2;
		construct(index * 2 + 1, l, m);
		construct(index * 2 + 2, m + 1, r);
		mat[index] = mul(mat[index * 2 + 1], mat[index * 2 + 2]);
	}
}

Tuple eval(int index, int l, int r, int first, int last) {
	if (first <= l && last >= r) {
		return mat[index];
	}
	int m = (l + r) / 2;
	if (first > m) {
		return eval(index * 2 + 2, m + 1, r, first, last);
	}
	else if (last <= m) {
		return eval(index * 2 + 1, l, m, first, last);
	}
	else {
		return mul(eval(index * 2 + 1, l, m, first, last), eval(index * 2 + 2, m + 1, r, first, last));
	}
}

unordered_map<long long, int> cache;
int f(int l, int r) {
	long long key = (long long)l * (n + 1) + r;
	auto it = cache.find(key);
	if (it != cache.end()) {
		return it->second;
	}
	Tuple m = eval(0, 0, n - 1, l, r - 1);
	return cache[key] = (long long)m.b * inv((1 - m.d + MOD) % MOD) % MOD;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int q;
	cin >> n >> q;
	p = vector<int>(n);
	int inv_100 = inv(100);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i] = (long long)p[i] * inv_100 % MOD;
	}
	construct(0, 0, n - 1);

	vector<int> is_checkpoint(n);
	set<int> checkpoints;
	is_checkpoint[0] = 1;
	checkpoints.insert(0);
	checkpoints.insert(n);
	long long result = f(0, n);
	for (int i = 0; i < q; ++i) {
		int u;
		cin >> u;
		--u;
		if (is_checkpoint[u]) {
			auto it = checkpoints.find(u);
			auto prev_it = it; --prev_it;
			auto next_it = it; ++next_it;
			result -= f(*prev_it, u);
			result -= f(u, *next_it);
			result += f(*prev_it, *next_it);
			checkpoints.erase(u);
		}
		else {
			auto next_it = checkpoints.upper_bound(u);
			auto prev_it = next_it; --prev_it;
			result -= f(*prev_it, *next_it);
			result += f(*prev_it, u);
			result += f(u, *next_it);
			checkpoints.insert(u);
		}
		is_checkpoint[u] ^= 1;
		result = (result % MOD + MOD) % MOD;
		printf("%d\n", (int)result);
	}
	return 0;
}