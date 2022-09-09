#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
//
struct x {
	long long start, stop;
};
//
bool cmp (x x1, x x2) {
	if (x1.start < x2.start) return true; else return false;
}
//
long long n, last_max, sum;
vector <x> a;
x x1;
//
int main() {
        //freopen("input.txt", "r", stdin);
       // freopen("output.txt", "w", stdout);
        //
        cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x1.start, &x1.stop);
			a.push_back(x1);
		}
		sort(a.begin(), a.end(), cmp);
		//
		last_max = -1;
		for (int i = 0; i < n; i++) {
			last_max = max(last_max, a[i].stop);
			if (a[i].stop < last_max) sum++;
		}
		//
		cout << sum;
}