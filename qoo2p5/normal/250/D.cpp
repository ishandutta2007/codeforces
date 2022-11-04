#include <iostream>
#include <cmath>

#define INF 1e10

using namespace std;

struct point {
	double x, y;
};

double dist(point p1, point p2) {
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

int n, m;
double a, b;
int ay[100000];
int by[100000];
double r[100000];

void input() {
	cin >> n >> m >> a >> b;

	for(int i = 0; i < n; i++) {
		cin >> ay[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> by[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> r[i];
	}
}


int main() {
	ios::sync_with_stdio(false);
	input();

	int left_point = 0;
	int right_point = 0;
	long double best = INF;

	int left1 = 0;
	for(int right = 0; right < m; right++) {
		double y = by[right] / b * a;

		while(left1 + 1 < n && ay[left1+1] <= y) left1++;
		int left2 = min(n-1, left2+1);

		double r1 = dist({0, 0}, {a, ay[left1]}) + dist({a, ay[left1]}, {b, by[right]});
		double r2 = dist({0, 0}, {a, ay[left2]}) + dist({a, ay[left2]}, {b, by[right]});

		if(r1 < r2) {
			if(r1 + r[right] < best) {
				best = r1 + r[right];
				left_point = left1;
				right_point = right;
			}
		} else {
			if(r2 + r[right] < best) {
				best = r2 + r[right];
				left_point = left2;
				right_point = right;
			}
		}
	}

	left_point++;
	right_point++;

	cout << left_point << " " << right_point << endl;

	return 0;
}