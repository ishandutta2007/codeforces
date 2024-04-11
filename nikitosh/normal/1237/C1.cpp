#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
 
#define FNAME ""
 
struct Point {
	int x, y, z, i;
	Point() {}
	bool operator<(const Point& p) const {
		if (x != p.x)
			return x < p.x;
		if (y != p.y)
			return y < p.y;
		return z < p.z;
	}
};

void solveZ(vector<Point>& v) {
	for (int i = 0; i < sz(v); i += 2)
		cout << v[i].i << " " << v[i + 1].i << "\n";
}

vector<Point> solveY(vector<Point>& v) {
	int i = 0;
	vector<Point> rest;
	//cout << "size=" << sz(v) << "\n";	
	while (i < sz(v)) {
		int j = i;
		vector<Point> vs;
		while (j < sz(v) && v[i].y == v[j].y)
			vs.pb(v[j]), j++;
		//cout << v[i].y << " " << sz(vs) << "\n";
		if (sz(vs) % 2 == 1)
			rest.pb(vs.back()), vs.pop_back();
		solveZ(vs);
		i = j;
	}
	for (int i = 0; i < sz(rest) - 1; i += 2)
		cout << rest[i].i << " " << rest[i + 1].i << "\n";
	if (sz(rest) % 2 == 1)
		return {rest.back()};
	return {};
}

void solveX(vector<Point>& v) {
	int i = 0;
	vector<Point> rest;
	while (i < sz(v)) {
		int j = i;
		vector<Point> vs;
		while (j < sz(v) && v[i].x == v[j].x)
			vs.pb(v[j]), j++;
		//cout << v[i].x << "\n";
		auto rem = solveY(vs);
		if (sz(rem))
			rest.pb(rem[0]);
		i = j;
	}
	for (int i = 0; i < sz(rest); i += 2)
		cout << rest[i].i << " " << rest[i + 1].i << "\n";
}
 
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
       
	int n;
	cin >> n;
	vector<Point> p(n);
	forn (i, n)
		cin >> p[i].x >> p[i].y >> p[i].z, p[i].i = i + 1;
	sort(all(p));
	solveX(p);
    return 0;
}