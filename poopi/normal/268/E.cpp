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
P arr[100000];

bool cmp(P a, P b){
	return (100 - b.second) * a.second * a.first > (100 - a.second) * b.second * b.first;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n, cmp);
	int64 res = 0;
	int64 sum = 0;
	for(int i = 0; i < n; i++){
		res += 10000 * arr[i].first + (100 - arr[i].second) * sum;
		sum += arr[i].first * arr[i].second;
	}
	cout << setprecision(6) << fixed << showpoint << (double)res / 10000 << endl;
	return 0;
}