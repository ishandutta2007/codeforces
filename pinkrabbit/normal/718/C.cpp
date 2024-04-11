#include <cstdio>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 100005;
const int MS = 262144;

struct M22{
	int a[2][2];
	inline M22() {}
	inline M22(int a00, int a01, int a10, int a11) {
		a[0][0] = a00;
		a[0][1] = a01;
		a[1][0] = a10;
		a[1][1] = a11;
	}
	inline int* operator[](int x) {
		return a[x];
	}
	inline friend M22 operator*(M22 p1, M22 p2) {
		M22 p3;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				p3[i][j] = 0;
				for (int k = 0; k < 2; ++k)
					p3[i][j] = (p3[i][j] + (LL)p1[i][k] * p2[k][j]) % Mod;
			}
		return p3;
	}
	inline friend M22 &operator*=(M22 &p1, M22 p2) {
		return p1 = p1 * p2;
	}
};

M22 Ex[30];
void Pre() {
	Ex[0] = M22(0, 1, 1, 1);
	for (int i = 1; i <= 29; ++i)
		Ex[i] = Ex[i - 1] * Ex[i - 1];
}
inline M22 Fib(int e) {
	M22 Ans(1, 0, 0, 1);
	for (int j = 0; e; ++j, e >>= 1)
		if (e & 1) Ans *= Ex[j];
	return Ans;
}

int N, Q;
int A[MN];

#define li (id << 1)
#define ri (id << 1 | 1)
#define mid (lb + rb >> 1)
#define ls li, lb, mid
#define rs ri, mid + 1, rb
int f1[MS], f2[MS]; M22 tg[MS];
inline void P(int id, M22 x) {
	int g1 = ((LL)f1[id] * x[0][0] + (LL)f2[id] * x[0][1]) % Mod;
	int g2 = ((LL)f1[id] * x[1][0] + (LL)f2[id] * x[1][1]) % Mod;
	f1[id] = g1, f2[id] = g2;
	tg[id] *= x;
}
inline void PD(int id) {
	P(id << 1, tg[id]), P(id << 1 | 1, tg[id]);
	tg[id] = M22(1, 0, 0, 1);
}
void Build(int id, int lb, int rb) {
	if (lb == rb) {
		f1[id] = 0, f2[id] = 1;
		tg[id] = M22(1, 0, 0, 1);
		P(id, Fib(A[lb]));
		return ;
	}
	Build(ls), Build(rs);
	f1[id] = (f1[li] + f1[ri]) % Mod;
	f2[id] = (f2[li] + f2[ri]) % Mod;
	tg[id] = M22(1, 0, 0, 1);
}
void Mdf(int id, int lb, int rb, int a, int b, M22 x) {
	if (rb < a || b < lb) return ;
	if (a <= lb && rb <= b) return P(id, x);
	PD(id);
	Mdf(ls, a, b, x), Mdf(rs, a, b, x);
	f1[id] = (f1[li] + f1[ri]) % Mod;
	f2[id] = (f2[li] + f2[ri]) % Mod;
}
LL Qur(int id, int lb, int rb, int a, int b) {
	if (rb < a || b < lb) return 0;
	if (a <= lb && rb <= b) return f1[id];
	PD(id);
	return Qur(ls, a, b) + Qur(rs, a, b);
}

int main() {
	Pre();
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i)
		scanf("%d", A + i);
	Build(1, 1, N);
	for (int i = 1; i <= Q; ++i) {
		int op, l, r, x;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) scanf("%d", &x), Mdf(1, 1, N, l, r, Fib(x));
		else printf("%lld\n", Qur(1, 1, N, l, r) % Mod);
	}
	return 0;
}