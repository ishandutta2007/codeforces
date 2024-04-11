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

int n, cnt = 0;
int arr[3010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		for(int j = 0; j < i; j++)
			if(arr[j] > arr[i])
				cnt++;
	}
	cout << (cnt / 2) * 4 + cnt % 2 << endl;
	return 0;
}