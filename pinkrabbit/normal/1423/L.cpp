#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>

typedef unsigned int ui;
typedef unsigned long long ull;
const ui Mod1 = 1000000009, Mod2 = 1000000007;
const ui Bas1 = 12232, Bas2 = 14124;

struct mybit {
	ull b[16];
	mybit() { memset(b, 0, sizeof b); }
	void clear() { memset(b, 0, sizeof b); }
	void flip(int z) { b[z >> 6] ^= 1llu << (z & 63); }
	ui cnt() {
		ui ret = 0;
		for (ui j = 0u; j < 16u; ++j)
			ret += __builtin_popcount(b[j]);
		return ret;
	}
	ull calc() {
		ui z1 = 0, z2 = 0;
		for (ui j = 0u; j < 16u; ++j)
			z1 = (z1 + b[j] % Mod1 * Bas1) % Mod1,
			z2 = (z2 + b[j] % Mod2 * Bas2) % Mod2;
		return (ull)z1 << 32 | z2;
	}
	void operator ^= (const mybit &p2) {
		for (ui j = 0u; j < 16u; ++j)
			b[j] ^= p2.b[j];
	}
};

int N, S, Z, Q;
mybit bits[31], now;

std::unordered_map<ull, int> mp;
void DFS1(int st, int k) {
	if (st > S) {
		ull z = now.calc();
		if (mp.find(z) != mp.end())
			mp[z] = std::min(mp[z], k);
		else
			mp[z] = k;
		return ;
	}
	DFS1(st + 1, k);
	now ^= bits[st];
	DFS1(st + 1, k + 1);
	now ^= bits[st];
}

int Ans;
void DFS2(int st, int k) {
	if (st > Z) {
		ull z = now.calc();
		if (mp.find(z) != mp.end())
			Ans = std::min(Ans, k + mp[z]);
		return ;
	}
	DFS2(st + 1, k);
	now ^= bits[st];
	DFS2(st + 1, k + 1);
	now ^= bits[st];
}

int main() {
	scanf("%d%d%d", &N, &S, &Q), Z = S / 3;
	for (int i = 1; i <= S; ++i) {
		ui c, x;
		scanf("%u", &c);
		while (c--) {
			scanf("%u", &x);
			bits[i].flip(x - 1);
		}
	}
	now.clear();
	DFS1(Z + 1, 0);
	while (Q--) {
		now.clear();
		ui c, x;
		scanf("%u", &c);
		while (c--) {
			scanf("%u", &x);
			now.flip(x - 1);
		}
		Ans = S + 1;
		DFS2(1, 0);
		printf("%d\n", Ans == S + 1 ? -1 : Ans);
	}
	return 0;
}