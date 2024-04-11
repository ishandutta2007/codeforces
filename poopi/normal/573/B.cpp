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
int arr[100010];
int l[100010];
int r[100010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	l[0] = 1;
	for(int i = 1; i < n; i++)
		l[i] = min(arr[i], l[i - 1] + 1);
	r[n - 1] = 1;
	for(int i = n - 2; i >= 0; i--)
		r[i] = min(arr[i], r[i + 1] + 1);
	int res = 0;
	for(int i = 0; i < n; i++)
		res = max(res, min(l[i], r[i]));
	cout << res << endl;
	return 0;
}