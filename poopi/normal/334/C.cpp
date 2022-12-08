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

int64 n;
int cnt = 0, p = 0;
int64 arr[100];

int main(){
	cin >> n;
	while(n){
		arr[p++] = n % 3;
		n /= 3;
	}
	int st = 0;
	while(arr[st] == 0)
		st++;
	for(int i = p - 1; i > st + 1; i--)
		arr[i - 1] += arr[i] * 3;
	cout << arr[st + 1] + 1 << endl;
	return 0;
}