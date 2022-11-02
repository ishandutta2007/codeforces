#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unordered_set<int> usint;

const int mxM = 50;
int m, n;
pair<usint, usint> v[mxM];

inline bool isIncluded(const usint& lhs, const usint& rhs) {
	for (int x : lhs) {
		if (rhs.find(x) == rhs.end())return false;
	}
	return true;
}

void input() {
	cin >> m >> n;
	int d, tmp;
	foru(i, 0, m) {
		cin >> d;
		while (d--) {
			cin >> tmp;
			v[i].first.insert(tmp);
		}
		foru(j, 0, n) {
			if (v[i].first.find(j + 1) == v[i].first.end())v[i].second.insert(j + 1);
		}
	}
}

bool solve() {
	foru(i, 0, m) {
		foru(j, 0, i) {
			if (isIncluded(v[i].first, v[j].second))return false;
			if (isIncluded(v[j].first, v[i].second))return false;
		}
	}
	return true;
}

int main() {
	fast;
	input();
	cout << (solve() ? "possible\n" : "impossible\n");
	return 0;
}