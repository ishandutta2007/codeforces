#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point{
	ll x;
	ll y;
	int ind;
};

bool comp(point a, point b) {
	if (a.x == b.x) return (a.y < b.y);
	return a.x < b.x;
}

int collinear(point a, point b, point c) {
	return ((b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y)) == 0;
}

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].ind = i+1;
	}
	sort(a.begin(), a.end(), comp);
	
	for (int i = 2; i < n; i++) {
		if (!collinear(a[0], a[1], a[i])) {cout << a[0].ind << " " << a[1].ind << " " << a[i].ind; return 0;}
	}
	
	return 0;
}