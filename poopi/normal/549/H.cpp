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

double a[4], b[4];
vector <double> v1, v2;

int main(){
	for(int i = 0; i < 4; i++)
		cin >> a[i];

	double l = 0, r = 2e9;
	for(int I = 0; I < 100; I++){
		double mid = (l + r) / 2;

		v1.clear();
		v2.clear();
		for(int i = -1; i <= 1; i += 2){
			for(int j = -1; j <= 1; j += 2){
				v1.push_back((a[0] + mid * i) * (a[3] + mid * j));
				v2.push_back((a[1] + mid * i) * (a[2] + mid * j));
			}
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		
		if(v1[0] <= v2[3] && v2[0] <= v1[3])
			r = mid;
		else l = mid;
	}
	cout << setprecision(10) << fixed << r << endl;
	return 0;
}