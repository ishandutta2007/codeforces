#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 1010;
const int S = (int)14e6;
int n;
int b[N];
int forSum[S];
int q[30];

void printAns(int m1, int m2) {
	int m3 = m1 & m2;
	m1 ^= m3;
	m2 ^= m3;
	int bal = 0;
	vector<int> A, B;
	for (int i = 0; i < min(30, n); i++) {
		if ((m1 >> i) & 1) {
			bal += b[i];
			A.push_back(b[i]);
		} else if ((m2 >> i) & 1) {
			bal -= b[i];
			B.push_back(b[i]);
		}
	}
	assert(bal == 0);
	assert((int)A.size() == (int)B.size());
	int x = 0;
	printf("YES\n");
	for (int i = 0; i < (int)A.size(); i++) {
		printf("%d ", x);
		x = A[i] - x;
		printf("%d ", x);
		x = B[i] - x;
	}
	assert(x == 0);
	m1 |= m2;
	for (int i = 0; i < n; i++) {
		if (i < 30 && ((m1 >> i) & 1)) continue;
		printf("%d ", b[i]);
	}
	printf("\n");
	exit(0);
}

void brute(int pos, int m, int lft, int mask, int sum) {
	if (lft == 0) {
		if (forSum[sum] == -1) {
			forSum[sum] = mask;
			return;
		} else {
			printAns(forSum[sum], mask);
			assert(false);
		}
	}
	if (pos + lft > m) return;
	brute(pos + 1, m, lft, mask, sum);
	brute(pos + 1, m, lft - 1, mask ^ (1 << pos), sum + b[pos]);
}

void trySolve(int m, int k) {
	memset(forSum, -1, sizeof(forSum));
	brute(0, m, k, 0, 0);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int cntEv = 0, cntOdd = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (b[i] & 1)
			cntOdd++;
		else
			cntEv++;
	}
	sort(b, b + n);
	int m = unique(b, b + n) - b;
	if (m < n) {
		printf("YES\n");
		for (int i = 0; i < m; i++)
			printf("%d ", b[i]);
		for (int i = m; i < n; i++)
			printf("0 ");
		printf("\n");
		return 0;
	}
	if (cntEv >= 3 || (cntEv >= 1 && cntOdd >= 2)) {
		if (cntEv >= 3) {
			cntEv = 3;
			cntOdd = 0;
		} else {
			cntEv = 1;
			cntOdd = 2;
		}
		vector<int> pos;
		for (int i = 0; i < n; i++) {
			if (b[i] & 1) {
				if (cntOdd > 0) {
					cntOdd--;
					pos.push_back(i);
				}
			} else {
				if (cntEv > 0) {
					cntEv--;
					pos.push_back(i);
				}
			}
		}
		assert((int)pos.size() == 3);
		int s = b[pos[0]] + b[pos[1]] + b[pos[2]];
		assert(s % 2 == 0);
		s /= 2;
		printf("YES\n");
		printf("%d %d %d ", s - b[pos[0]], s - b[pos[1]], s - b[pos[2]]);
		s -= b[pos[0]];
		for (int i = 0; i < n; i++) {
			if (i == pos[0] || i == pos[1] || i == pos[2]) continue;
			printf("%d ", b[i] - s);
		}
		printf("\n");
		return 0;
	}
	if (cntOdd != n) {
		printf("NO\n");
		return 0;
	}
	if (n < 27) {
		for (int ppc = 2; 2 * ppc <= n; ppc++)
			trySolve(n, ppc);
		printf("NO\n");
	} else {
		trySolve(27, 13);
		assert(false);
	}

	return 0;
}