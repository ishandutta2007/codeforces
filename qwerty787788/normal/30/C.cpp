#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//
struct sob {
	int x, y, t;
	double p;
};
bool cmp(sob s1, sob s2) {
	if (s1.t < s2.t) return true; else return false;
}
//
vector <sob> a;
//
int n;
double sum[1001];
//

//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	sob s;
	s.t = -1;
	a.push_back(s);
	for (int i =0 ; i < n; i++) {
		cin >> s.x >> s.y >> s.t >> s.p;
		a.push_back(s);
	}
	sort(a.begin(), a.end(), cmp);
	//
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			bool ok = false;
			if (j == 0) ok = true;
			int t = a[i].t-a[j].t;
			double dist = sqrt((a[j].x-a[i].x)*(a[j].x-a[i].x)+(a[j].y-a[i].y)*(a[j].y-a[i].y)+0.0);
			if (dist <= t) ok = true;
			if (ok) sum[i] = max(sum[i], sum[j]+a[i].p);
		}
	}
	//
	double max = 0;
	for (int i = 1; i <= n; i++) 
		if (sum[i] > max) max = sum[i];
	cout .precision(8);
	cout << max << endl;
	//
	return 0;
}