#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
const int Mod = 2520;

inline int lcm(int a, int b) { return a * b / std::__gcd(a, b); }
int Div[48], Tr[48][10], Id[Mod + 1], Cnt;
inline void Init() {
	for (int i = 1; i <= Mod; ++i) if (!(Mod % i))
		Div[Cnt] = i, Id[i] = Cnt, Tr[Cnt][0] = Cnt, Cnt++;
	for (int i = 0; i < 48; ++i) for (int j = 1; j < 10; ++j)
		Tr[i][j] = Id[lcm(Div[i], j)];
}

LL f[20][48][Mod];
LL dp(LL N) {
	if (!N) return 1ll;
	static int num[20]; int k = 0;
	while (N) num[k++] = N % 10, N /= 10;
	int _id = 0, _mod = 0;
	memset(f, 0, sizeof f);
	for (int i = k; i; --i) {
		int nc = num[i - 1];
		for (int j = 0; j < 48; ++j) {
			for (int k = 0; k < Mod; ++k) {
				if (!f[i][j][k]) continue;
				int kk = k * 10 % Mod;
				LL v = f[i][j][k];
				for (int l = 0; l < 10; ++l)
					f[i - 1][Tr[j][l]][kk + l] += v;
			}
		}
		_mod = _mod * 10 % Mod;
		for (int l = 0; l < nc; ++l)
			++f[i - 1][Tr[_id][l]][_mod + l];
		_id = Tr[_id][nc], _mod += nc;
	}
	LL Ans = !(_mod % Div[_id]);
	for (int j = 0; j < 48; ++j)
		for (int k = 0; k < Mod; k += Div[j])
			Ans += f[0][j][k];
	return Ans;
}

int main() {
	Init();
	int T; scanf("%d", &T);
	while (T--) {
		LL l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", dp(r) - dp(l - 1));
	}
	return 0;
}