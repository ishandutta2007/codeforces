										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

double a, v, l, d, w;

bool gr(double a, double b){
	return a - 1e-9 > b;
}

double calc(double v0, double len, double mxv){
	double t0 = (-v0 + sqrt(v0 * v0 + 2 * a * len)) / a;
	double t1 = (mxv - v0) / a;
	if(gr(t1, t0))
		return t0;
	len -= t1 * (mxv + v0) / 2;
	return t1 + len / mxv;
}

int main(){
	cin >> a >> v >> l >> d >> w;
	w = min(w, v);
	double res = 0;
	double t = sqrt(2 * d) / sqrt(a);
	double v1 = sqrt(2 * a * d);
	if(gr(v1, w)){
		t = w / a;
		res = t + 2 * calc(w, (d - w * t / 2) / 2, v);
		v1 = w;
	}
	else res = t;
	res += calc(v1, l - d, v);
	cout << setprecision(9) << fixed << showpoint << res << endl;
	return 0;
}