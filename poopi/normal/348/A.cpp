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

int n;
int64 sum, mx;

int main(){
	cin >> n;
	int64 a;
	for(int i = 0; i < n; i++){
		cin >> a;
		sum += a;
		mx = max(mx, a);
	}
	cout << max(mx, (sum - 1) / (n - 1) + 1) << endl;
	return 0;
}