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

int arr[6];

int main(){
	for(int i = 0; i < 6; i++)
		cin >> arr[i];
	int bef = arr[0];
	int cnt = 0;
	for(int i = 1; i <= arr[1] + arr[2]; i++){
		int cur = bef;
		if(i <= arr[1] && i <= arr[5])
			cur++;
		if(i > arr[1] && i > arr[5])
			cur--;
		cnt += bef + cur;
		bef = cur;
	}
	cout << cnt << endl;
	return 0;
}