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

int m, r;

int main(){
	cin >> m >> r;
	if(m == 1){
		cout << setprecision(8) << fixed << showpoint << 2. * r << endl;
		return 0;
	}
	double res = 0;
	for(int i = 0; i < m; i++){
		double avg = 0;
		double s1 = (double)i * (i + 1);
		double s2 = (double)(m - i - 1) * (m - i);
		int red = 2 * m - 2;
		if(i == 0 || i == m - 1)
			red--;
		else red -= 2;
		avg = (s1 + s2 - red * (2 - sqrt(2.))) / m;
		res += avg;
	}
	cout << setprecision(8) << fixed << showpoint << (res / m + 2) * r << endl;
	return 0;
}