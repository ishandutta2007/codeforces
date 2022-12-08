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

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = n; i >= k + 1; i--)
		cout << i << ' ';
	int sg = -1, num = k + 1;
	for(int i = k; i > 0; i--){
		num += sg * i;
		cout << num << ' ';
		sg *= -1;
	}
	cout << endl;
	return 0;
}