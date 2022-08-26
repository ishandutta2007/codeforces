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

struct Point {
	int x, y;

	Point() : x(), y() {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	void scan() {
		scanf("%d%d", &x, &y);
	}

	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll operator % (const Point &a) const {
		return (ll)x * a.x + (ll)y * a.y;
	}
	double len() const {
		return sqrt(*this % *this);
	}
	ll operator * (const Point &a) const {
		return (ll)x * a.y - (ll)y * a.x;
	}

	bool operator < (const Point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
	bool operator == (const Point &a) const {
		return x == a.x && y == a.y;
	}
};

const double INF = 1e9;
const int N = 200200;
int n;
Point a[N];
Point B;
Point S;
double ANS = INF;
double d[N];
double e[N];

void read() {
	int k;
	scanf("%d%d", &n, &k);
	k--;
	for (int i = 0; i < n; i++) {
		a[i].scan();
	}
	S = a[k];
	vector<int> pos;
	for (int i = 0; (int)pos.size() < 3 && i < n; i++) {
		bool ok = true;
		for (int x : pos)
			ok &= !(a[i] == a[x]);
		if (ok) pos.push_back(i);
	}
	assert((int)pos.size() == 3);
	bool fnd = false;
	for (int p = 0; !fnd && p < 3; p++)
		for (int q = p + 1; !fnd && q < 3; q++) {
			Point P = a[pos[p]], Q = a[pos[q]];
			int id = -1;
			for (int i = 0; id >= -1 && i < n; i++)
				if ((Q - P) * (a[i] - P) != 0) {
					if (id == -1)
						id = i;
					else
						id = -2;
				}
			if (id == -2) continue;
			assert(id != -1);
			B = a[id];
			for (int i = id; i < n - 1; i++)
				a[i] = a[i + 1];
			n--;
			fnd = true;
		}
	assert(fnd);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		d[i] = (a[i] - a[0]).len();
	for (int i = 0; i < n; i++)
		e[i] = (B - a[i]).len();
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	if (S == B) {
		printf("%.13lf\n", min(e[0], e[n - 1]) + d[n - 1]);
		return 0;
	}
	int p = 0;
	while(!(a[p] == S)) p++;
	int l = 0, r = n - 1;
	while (a[l] == S) l++;
	while (a[r] == S) r--;
	ANS = min(ANS, e[p] + min(e[l], e[r]) + d[r] - d[l]);
	ANS = min(ANS, e[0] + 2 * d[n - 1] - d[p] - d[0]);
	ANS = min(ANS, e[n - 1] + d[n - 1] + d[p] - 2 * d[0]);
	for (int i = 1; i < n; i++) {
		double cur = 0;
		if (i <= p) {
			cur += min(e[i] + 2 * d[n - 1] - d[p] - d[i], e[n - 1] + d[n - 1] + d[p] - 2 * d[i]);
			cur += min(e[0], e[i - 1]) + d[i - 1] - d[0];
		} else {
			cur += min(e[0] + 2 * d[i - 1] - d[p] - d[0], e[i - 1] + d[i - 1] + d[p] - 2 * d[0]);
			cur += min(e[i], e[n - 1]) + d[n - 1] - d[i];
		}
		ANS = min(ANS, cur);
	}
	printf("%.13lf\n", ANS);

	return 0;
}