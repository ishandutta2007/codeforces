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

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] <= 0)
			cnt++;
	}
	int mn = Inf;
	for(int i = 0; i < n - 1; i++){
		if(arr[i] < 0)
			cnt--;
		if(arr[i] > 0)
			cnt++;
		mn = min(mn, cnt);
	}
	cout << mn << endl;
	return 0;
}