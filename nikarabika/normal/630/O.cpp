//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LD, LD> pdd;
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

LD ang, PI;
Point O;
LD Sin, Cos;

Point rotat(Point A){
	A -= O;
	LD X = A.x, Y = A.y;
	return O + Point(X * Cos + Y * Sin, -X * Sin + Y * Cos);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	PI = atan(1) * 4;
	LD px, py, vx, vy, a, b, c, d;
	cin >> px >> py >> vx >> vy
		>> a >> b >> c >> d;
	ang = -(arg(Point(vx, vy)) - PI / 2);
	Sin = sin(ang);
	Cos = cos(ang);
	pdd Po[7];
	Po[0] = {px, py + b};
	Po[1] = {px - a / 2, py};
	Po[2] = {px - c / 2, py};
	Po[3] = {px - c / 2, py - d};
	Po[4] = {px + c / 2, py - d};
	Po[5] = {px + c / 2, py};
	Po[6] = {px + a / 2, py};
	O = Point(px, py);
	cout.precision(15);
	for(int i = 0; i < 7; i++)
		cout << fixed << rotat(Point(Po[i].L, Po[i].R)).x << ' ' << rotat(Point(Po[i].L, Po[i].R)).y << '\n';
	return 0;
}