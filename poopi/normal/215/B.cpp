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
#define PLL pair<int64, int64>

int n, r1, p1, p2;
double A, B;

int main(){
	int x;
	cin >> n >> r1;
	for(int i = 1; i < n; i++){
		cin >> x;
		r1 = max(r1, x);
	}
	cin >> n >> p1;
	for(int i = 1; i < n; i++){
		cin >> x;
		p1 = max(p1, x);
	}
	cin >> n >> p2;
	for(int i = 1; i < n; i++){
		cin >> x;
		p2 = min(p2, x);
	}
	cin >> A >> B;
	double tmp = (A * p2) / (B * p1) + 1;
	double r2 = sqrt(r1 * r1 / tmp);
	cout << setprecision(8) << showpoint << fixed << r2 << endl;
    return 0;
}