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
int arr[100010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	string res = "NO";
	for(int i = 0; i + 1 < n; i++)
		if(arr[i] < arr[i + 1] && arr[i] * 2 > arr[i + 1])
			res = "YES";
	cout << res << endl;
	return 0;
}