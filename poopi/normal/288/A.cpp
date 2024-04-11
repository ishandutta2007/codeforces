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
#define P pair<int, double>
#define PLL pair<int64, int64>

int n, k;

int main(){
	cin >> n >> k;
	if(k > n){
		cout << -1 << endl;
		return 0;
	}
	if(k == 1){
		if(n == 1)
			cout << 'a' << endl;
		else cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n - k + 2; i++)
		cout << (char)('a' + i % 2);
	for(int i = 2; i < k; i++)
		cout << (char)('a' + i);
	cout << endl;
	return 0;
}