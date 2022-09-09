#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
#include <cstdio>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
long long n, a, d;
long long t, v;
//
double time(double len, double v, double a) {
	double t = v/a;
	if (a*t*t/2.0 <= len) {
		double ans = v/a;
		len -= a*t*t/2.0;
		ans += len/v;
		return ans;
	} else {
		double ans = sqrt(2.0*len/a);
		return ans;
	}
};
//
int main() {
	//freopen("Input.txt", "r", stdin);
	//freopen("Output.txt", "w", stdout);
	//
	scanf("%d %d %d", &n, &a, &d);
	double minT = 0;
	for (int i = 0; i < n; i++) {

		scanf("%d %d", &t, &v);
		double t1 = t + time(d, v, a);
		if (t1 < minT) t1 = minT; else minT = t1;
		printf("%.9lf\n", t1);
	}
	//
}