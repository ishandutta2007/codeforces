#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>

typedef double r64;
typedef long long LL;
const r64 eps = 1e-6;
const int MN = 50005;

int N, M;
r64 k[MN], b[MN], Ans;

LL check(r64 rad, int typ) {
	static r64 t[MN * 2];
	static int p[MN * 2], ip[MN * 2], lid[MN], bit[MN * 2];
	static std::set<int> st;
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		r64 d = (k[i] * k[i] + 1) * rad * rad - b[i] * b[i], x, y;
		if (d < 0) continue;
		d = sqrt(d);
		x = (-k[i] * b[i] + d) / (k[i] * k[i] + 1), y = k[i] * x + b[i];
		t[++cnt] = atan2(y, x), p[cnt] = cnt;
		x = (-k[i] * b[i] - d) / (k[i] * k[i] + 1), y = k[i] * x + b[i];
		t[++cnt] = atan2(y, x), p[cnt] = cnt;
		if (t[cnt - 1] > t[cnt]) std::swap(t[cnt - 1], t[cnt]);
		lid[cnt / 2] = i;
	}
	std::sort(p + 1, p + cnt + 1, [](int i, int j) { return t[i] < t[j]; });
	for (int i = 1; i <= cnt; ++i) ip[p[i]] = i;
	if (typ) {
		int sum = 0;
		for (int id = 1; id <= cnt; ++id) {
			int i = p[id];
			if (i & 1) st.insert(id);
			else {
				st.erase(ip[i - 1]);
				for (auto it = st.lower_bound(ip[i - 1]); it != st.end(); ++it) {
					int u = lid[p[*it] / 2 + 1], v = lid[i / 2];
					r64 x = (b[u] - b[v]) / (k[v] - k[u]);
					r64 y = k[u] * x + b[u];
					Ans += sqrt(x * x + y * y);
					++sum;
				}
			}
		}
		return sum;
	} else {
		for (int i = 1; i <= cnt; ++i) bit[i] = 0;
		auto Add = [&](int i, int x) { for (; i <= cnt; i += i & -i) bit[i] += x; };
		auto Qur = [&](int i) { int a = 0; for (; i; i -= i & -i) a += bit[i]; return a; };
		int num = 0; LL sum = 0;
		for (int id = 1; id <= cnt; ++id) {
			int i = p[id];
			if (i & 1) Add(id, 1), ++num;
			else sum += num - Qur(ip[i - 1]), Add(ip[i - 1], -1), --num;
		}
		return sum;
	}
}

int main() {
	r64 ox, oy;
	scanf("%d%lf%lf%d", &N, &ox, &oy, &M);
	ox /= 1000, oy /= 1000;
	for (int i = 1; i <= N; ++i) {
		scanf("%lf%lf", &k[i], &b[i]);
		k[i] /= 1000, b[i] /= 1000;
		b[i] += ox * k[i] - oy;
	}
	r64 lb = 0, rb = 2.1e9, mid, ans = 0;
	while (lb <= rb - eps) {
		mid = (lb + rb) / 2;
		if (check(mid, 0) < M) ans = lb = mid;
		else rb = mid;
	}
	int num = check(ans, 1);
	printf("%.10f\n", Ans + (M - num) * ans);
	return 0;
}