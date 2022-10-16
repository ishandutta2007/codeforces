#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(8);
	
	int hh, mm;
	cin >> hh >> mm;
	int h, d, n; double c;
	cin >> h >> d >> c >> n;
	
	if (hh >= 20) {
		c *= 0.8;
		int food;
		if (h % n == 0) {
			food = h/n;
		} else {food = h/n + 1;}
		cout << c*food;
		return 0;
	} 
	
	mm += hh*60;
	
	double ans1;
	int food;
	if (h % n == 0) {
		food = h/n;
	} else {food = h/n + 1;}
	ans1 = c*food;
	
	c *= 0.8;
	double ans2;
	
	h += (1200 - mm)*d;
	if (h % n == 0) {
		food = h/n;
	} else {food = h/n + 1;}
	ans2 = c*food;
	
	cout << min(ans1, ans2);
	
	return 0;
}