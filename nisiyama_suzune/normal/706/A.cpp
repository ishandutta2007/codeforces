//IO
#include <iostream>
#include <cstdio>
#include <iomanip>

//General
#include <cmath>
#include <cstdlib>
#include <cstring>

//STL
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1E9;

double x, y;
int N;

double sqr (double x) {
	return x * x;
}

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> x >> y;
	cin >> N;
	double best = 1E18;
	for (int i = 0; i < N; i++) {
		double px, py, v;
		cin >> px >> py >> v;
		double t = sqrt (sqr (px - x) + sqr (py - y)) / v;
		if (best > t) best = t;
	}
	cout << fixed << setprecision (10) << best << endl;
	return 0;
}