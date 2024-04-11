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

string arr[6] = {"170", "020", "200", "110", "050", "080"};

int main(){
	int n;
	cin >> n;
	if(n <= 2)
		cout << -1 << endl;
	else if(n == 3)
		cout << 210 << endl;
	else{
		cout << 1;
		for(int i = 0; i < n - 4; i++)
			cout << 0;
		cout << arr[n % 6] << endl;
	}

	return 0;
}