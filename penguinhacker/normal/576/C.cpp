#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int K = 1000;
int n;
struct Point {
	int x, y, block, ind;
	bool operator<(const Point& o) const {
		return block != o.block ? block < o.block : y < o.y;
	}
} p[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y, --p[i].x, --p[i].y;
		p[i].block = p[i].x / K;
		p[i].ind = i + 1;
	}
	sort(p, p + n);
	for (int i = 0; i < n; ++i) {
		cout << p[i].ind << " ";
	}
	return 0;
}