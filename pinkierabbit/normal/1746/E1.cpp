#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <numeric>
#include <cstdlib>
using std::scanf, std::printf, std::puts;

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) std::fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

void Init();
void Solve();
int main() {
	Init();
	int tests = 1;
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

typedef long long LL;
const int Mod = 998244353;

const int Inf = 0x3f3f3f3f;
const LL InfLL = 0x3f3f3f3f3f3f3f3f;

const int MN = 500005;

int n;

void Init() {
}

std::set<int> con(std::set<int> s1, std::set<int> s2) {
	s1.insert(s2.begin(), s2.end());
	return s1;
}
std::set<int> con(std::set<int> s1, std::set<int> s2, std::set<int> s3) {
	s1.insert(s2.begin(), s2.end());
	s1.insert(s3.begin(), s3.end());
	return s1;
}
void print(std::set<int> s) {
	int sz = (int)s.size();
	printf("? %d", sz);
	for (int x : s)
		printf(" %d", x);
	puts("");
	std::fflush(stdout);
}
int ask(std::set<int> s) {
	print(s);
	char str[3];
	scanf("%s", str);
	return *str == 'Y';
}

void guess(int x) {
	printf("! %d\n", x);
	std::fflush(stdout);
	char str[3];
	scanf("%s", str);
	if (str[1] == ')')
		std::exit(0);
}

void Solve(std::set<int> s) {
	int sz = (int)s.size();
	if (sz >= 4) {
		int a[4] = {sz / 4, sz / 4, sz / 4, sz / 4};
		F2(i, 0, sz % 4) ++a[i];
		std::vector<int> v(s.begin(), s.end());
		std::set<int> u[4];
		auto it = v.begin();
		F2(i, 0, 4) {
			u[i] = std::set<int>(it, it + a[i]);
			it += a[i];
		}
		int r1 = ask(con(u[0], u[1]));
		int r2 = ask(con(u[0], u[2]));
		if (r1 && r2)
			Solve(con(u[0], u[1], u[2]));
		if (r1 && !r2)
			Solve(con(u[0], u[1], u[3]));
		if (!r1 && r2)
			Solve(con(u[0], u[2], u[3]));
		if (!r1 && !r2)
			Solve(con(u[1], u[2], u[3]));
	} else {
		std::vector<int> v(s.begin(), s.end());
		int r1 = ask({v[0]});
		if (r1 || ask({v[0]})) {
			guess(v[0]);
			int r2 = ask({v[1]});
			if (r2)
				guess(v[1]);
			else
				guess(v[2]);
		} else {
			int r2 = ask({v[1]});
			if (r2)
				guess(v[1]);
			else
				guess(v[2]);
		}
	}
}

void Solve() {
	scanf("%d", &n);
	if (n == 1) {
		guess(1);
		return ;
	}
	if (n == 2) {
		guess(1);
		guess(2);
		return ;
	}
	std::vector<int> v(n);
	std::iota(v.begin(), v.end(), 1);
	std::set<int> s(v.begin(), v.end());
	Solve(s);
}