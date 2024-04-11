										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
double R, r;

bool gr(double a, double b){
	return a - 1e-9 > b;
}

int main(){
	while(cin >> n >> R >> r){
		if(gr(r, R)){
			cout << "NO" << endl;
			continue;
		}
		if(gr(2 * r, R)){
			cout << (n > 1 ? "NO" : "YES") << endl;
			continue;
		}
		double tmp = r / (R - r);
		double al = asin(tmp);
		al = (al * 180.) / acos(-1.);
		al = al * 2. * n;
		cout << (gr(al, 360) ? "NO" : "YES") << endl;

	}
	return 0;
}