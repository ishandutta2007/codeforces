// https://codeforces.com/contest/1237/submission/62722869
// clearly n^3
#include <bits/stdc++.h>
 
#pragma GCC target("avx,tune=native,sse4")
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 200013
#define INF 1000000000000000000LL
#define MOD 1000000007LL
#define IINF 1000000000
#define mp make_pair
#define pb push_back
#define remove pop
#define all(x) x.begin(), x.end()
 
struct Point {
	int x, y, z;
	int id;
 
	Point(){}
 
	Point(int a, int b, int c, int i) {
		x = a; y = b; z = c; id = i;
	}
 
	const bool operator<(const Point &other) const {
		if (x == other.x) {
			if (y == other.y) {
				return z < other.z;
			}
			return y < other.y;
		}
		return x < other.x;
	}
 
} points[MAXN];
bool used[MAXN];
 
 
bool cmpY(const Point &p1, const Point &p2) {
	if (p1.y == p2.y) {
		return p1.z < p2.z;
	}
	return p1.y < p2.y;
}
 
bool cmpZ(const Point &p1, const Point &p2) {
	return p1.z < p2.z;
}
 
int n;
 
vector<pair2> answer;
 
int main() {
	if (fopen("FILENAME.in", "r")) {
		freopen("FILENAME.in", "r", stdin);
		freopen("FILENAME.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
 
	cin >> n;
 
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		points[i] = Point(a, b, c, i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (used[i] || used[j]) continue;
 
			int minx = min(points[i].x, points[j].x);
			int miny = min(points[i].y, points[j].y);
			int minz = min(points[i].z, points[j].z);
 
			int maxx = max(points[i].x, points[j].x);
			int maxy = max(points[i].y, points[j].y);
			int maxz = max(points[i].z, points[j].z);
 
			bool bad = false;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) continue;
				if (used[k]) continue;
 
				if (minx <= points[k].x && points[k].x <= maxx && miny <= points[k].y && points[k].y <= maxy && minz <= points[k].z && points[k].z <= maxz) {
					//bad
					bad = true;
					break;
				}
			}
 
			if (!bad) {
				answer.pb(mp(points[i].id, points[j].id));
				used[i] = true; used[j] = true;
			}
		}
	}
 
	for (pair2 p : answer) {
		cout << p.first + 1 << ' ' << p.second + 1 << endl;
	}
}
 
//GCD GCD GCD USE GCD IN MATH