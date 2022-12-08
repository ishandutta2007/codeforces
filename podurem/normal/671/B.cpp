#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forq(i, q, n) for (int i = (int)q; i < (int)n; ++i)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define X first
#define Y second
#define TASK "donut"

const int INF = (int)1e9 + 7;
const ll LINF = (ll)1e18 + 7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e6 + 7;
const double EPS = (double)1e-6;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

int main() {
	file();
	ll n, k;
	scanf("%I64d%I64d", &n, &k);
	vector <ll> A(n);
	ll sss = 0;
	forn(i, n) {
		scanf("%I64d", &A[i]);
		sss += A[i];
	}
	sss = (sss % n != 0);
	sort(all(A));
	ll sum = A[0], ksum = 0;
	vector <ll> dp(n);
	dp[0] = 0;
	ll x = -1;
	forq(i, 1, n) {
		ksum = A[i] * i - sum;
		dp[i] = ksum;
		if (ksum > k) {
			x = i;
			break;
		}
		sum += A[i];
	}
	if (x == -1) {
		cout << sss;
		return 0;
	}
	ll lllll = A[n - 1];
	forn(i, n) {
		A[i] = A[n - 1] - A[i] + 1;
	}
	sort(all(A));
	vector <ll> dp1(n);
	dp1[0] = 0;
	sum = A[0], ksum = 0;
	ll x1 = -1;
	forq(i, 1, n) {
		ksum = A[i] * i - sum;
		dp1[i] = ksum;
		if (ksum > k) {
			x1 = i;
			break;
		}
		sum += A[i];
	}
	if (x1 == -1) {
		cout << sss;
		return 0;
	}
	ll raz = k - dp[x - 1];
	forn(i, n) {
		A[i] = lllll - A[i] + 1;
	}
	sort(all(A));
	ll minz = A[x - 1] + raz / x;
	raz = k - dp1[x1 - 1];
	forn(i, n) {
		A[i] = lllll - A[i] + 1;
	}
	sort(all(A));
	ll maxz = A[x1 - 1] + raz / x1;
	maxz = lllll - maxz + 1;
	cout << max(sss, maxz - minz);
	return 0;
}