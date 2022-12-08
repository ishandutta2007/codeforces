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

int n, t;
int arr[100000];
bool can[100000];

int main(){
	cin >> n >> t;
	can[t - 1] = true;
	for(int i = 0; i < n - 1; i++)
		cin >> arr[i];
	for(int i = n - 1; i >= 0; i--)
		if(can[i + arr[i]])
			can[i] = true;
	cout << (can[0] ? "YES" : "NO") << endl;
	return 0;
}