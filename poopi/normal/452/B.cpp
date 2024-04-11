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

int n, m;

int main(){
	cin >> n >> m;
	if(n == 0){
		cout << 0 << ' ' << 1 << endl;
		cout << 0 << ' ' << m << endl;
		cout << 0 << ' ' << 0 << endl;
		cout << 0 << ' ' << m - 1 << endl;
	}
	else if(m == 0){
		cout << 1 << ' ' << 0 << endl;
		cout << n << ' ' << 0 << endl;
		cout << 0 << ' ' << 0 << endl;
		cout << n - 1 << ' ' << 0 << endl;
	}
	else{
		double t1 = 2 * sqrt((double)m * m + (n - 1) * (n - 1));
		double t2 = 2 * sqrt((double)n * n + (m - 1) * (m - 1));
		double t3 = max(n, m) + sqrt((double)n * n + m * m);
		double mx = max(t1, max(t2, t3));
		if(fabs(mx - t1) < 1e-9){
			cout << 1 << ' ' << 0 << endl;
			cout << n << ' ' << m << endl;
			cout << 0 << ' ' << 0 << endl;
			cout << n - 1 << ' ' << m << endl;
		}
		else if(mx - t2 < 1e-9){
			cout << 0 << ' ' << 1 << endl;
			cout << n << ' ' << m << endl;
			cout << 0 << ' ' << 0 << endl;
			cout << n << ' ' << m - 1 << endl;
		}
		else{
			cout << 0 << ' ' << 0 << endl;
			cout << n << ' ' << m << endl;
			if(n < m){
				cout << n << ' ' << 0 << endl;
				cout << 0 << ' ' << m << endl;
			}
			else{
				cout << 0 << ' ' << m << endl;
				cout << n << ' ' << 0 << endl;
			}
		}
	}
	return 0;
}