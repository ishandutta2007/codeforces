//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef complex<LD> Point;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define x real()
#define y imag()

LD n, r, PI;

LD cross(Point A, Point B){
	return A.x * B.y - A.y * B.x;
}

Point get(int idx){
	return r * Point(cos(idx * PI / n), sin(idx * PI / n));
}

Point intersect(Point A, Point B, Point C, Point D){
	LD alpha = cross(C - A, D - C) / cross(B - A, D - C);
	return A + alpha * (B - A);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	PI = atan(1) * 8;
	cin >> n >> r;
	Point P0 = get(0), P1 = get(1), P2 = get(-1),
		  P3 = get(n / 2 + 0), P4 = get(n / 2 + 1), P5 = get(n / 2 - 1),
		  P6 = get(0 - n / 2), P7 = get(1 - n / 2), P8 = get(-1 - n / 2);
	//cout << P0 << endl;
	Point X = intersect(P0, P3, P1, P7),
		  Y = intersect(P0, P6, P2, P5);
	LD area = cross(Point(0, 0), Y)
		+ cross(Y, P0)
		+ cross(P0, X)
		+ cross(X, Point(0, 0));
	cout.precision(15);
	cout << fixed << n / 2 * area << endl;
	return 0;
}