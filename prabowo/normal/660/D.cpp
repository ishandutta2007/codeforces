#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
	while(x > 0 && y > 0)
		x > y ? x %= y : y %= x;
	return x + y;
}

struct Point {
	long long x, y;
	Point() {}
	Point(long long _x, long long _y) : x(_x), y(_y) {}
	Point operator + (const Point &a) const { return Point(x + a.x, y + a.y); }
	bool operator < (const Point &a) const { return x < a.x || x == a.x && y < a.y; }
	bool operator == (const Point &a) const { return x == a.x && y == a.y; }
};

struct Line {
	long long a, b, c;
	Line() {}
	Line(Point p, Point q) {
		long long d, A, B, C;
		A = q.y - p.y;
		B = p.x - q.x;
		C = A * p.x + B * p.y;
		d = gcd(abs(C), gcd(abs(A), abs(B)));
		A /= d;
		B /= d;
		C /= d;
		if(A < 0 || A == 0 && B < 0) A *= -1, B *= -1, C *= -1;
		a = A;
		b = B;
		c = C;
	}
	bool operator < (const Line &ot) const { return a < ot.a || a == ot.a && (b < ot.b || b == ot.b && c < ot.c); }
	bool operator == (const Line &ot) const { return a == ot.a && b == ot.b && c == ot.c; }
};

long long nums(long long U) { return (1 + sqrt(1 + 8 * U)) / 2; }

vector <Point> v;
vector <Line> line;
Point a[2005];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%I64d %I64d", &a[i].x, &a[i].y);
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			v.push_back(a[i] + a[j]);
			Line tmp(a[i], a[j]);
			line.push_back(tmp);
		}
	}
	
	sort(v.begin(), v.end());
	sort(line.begin(), line.end());
	
	long long ans = 0;
	
	
	for(int i = 0; i < v.size(); ) {
		int j = i + 1;
		while(j < (int) v.size() && v[i] == v[j]) j++;
		ans += (long long) (j - i) * (j - i - 1) / 2;
		i = j;
	}
	
	for(int i = 0; i < line.size(); ) {
		int j = i + 1;
		while(j < (int) line.size() && line[i] == line[j]) j++;
		long long cur = nums(j - i);
		ans -= cur * (cur - 1) / 2 * (cur - 2) / 3 * (cur - 3) / 4;
		i = j;
	//	printf("%lld %lld %lld\n", line[i].a, line[i].b, line[i].c);
	}
	
/*
	for(map <Point, long long> :: iterator it = cnt.begin(); it != cnt.end(); ++it)
		ans += (it -> second) * (-1 + it -> second) / 2;

	for(map <Line, long long> :: iterator it = cnt2.begin(); it != cnt2.end(); ++it) {
		long long cur = nums(it -> second);
//		printf("%I64d %I64d\n", it -> second, cur);
	}
*/		
	printf("%I64d\n", ans);
	return 0;
}