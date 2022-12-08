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

int n;
int ref[100010];
int arr[100010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		ref[arr[i]] = i;
	}
	int m, b;
	int64 c1 = 0, c2 = 0;
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> b;
		c1 += ref[b] + 1;
		c2 += n - ref[b];
	}
	cout << c1 << ' ' << c2 << endl;
    return 0;
}