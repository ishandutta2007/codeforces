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

int n, p;
int arr[100010];
int lis[100010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		lis[i] = n + 1;
	}
	for(int i = 0; i < n; i++){
		int idx = lower_bound(lis, lis + p + 1, arr[i]) - lis;
		lis[idx] = arr[i];
		if(idx == p)
			p++;
	}
	cout << p << endl;
	return 0;
}