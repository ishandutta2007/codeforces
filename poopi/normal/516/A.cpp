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

int n, cnt[10];

int main(){
	cin >> n;
	char c;
	for(int i = 0; i < n; i++){
		cin >> c;
		int t = c - '0';
		for(int i = 1; i <= t; i++)
			cnt[i]++;
	}
	cnt[2] += 2 * cnt[4] + cnt[6] + 3 * cnt[8];
	cnt[3] += cnt[6] + 2 * cnt[9];
	for(int i = 0; i < cnt[7]; i++){
		cout << 7;
		cnt[5]--;
		cnt[3] -= 2;
		cnt[2] -= 4;
	}
	for(int i = 0; i < cnt[5]; i++){
		cout << 5;
		cnt[3]--;
		cnt[2] -= 3;
	}
	for(int i = 0; i < cnt[3]; i++){
		cout << 3;
		cnt[2]--;
	}
	for(int i = 0; i < cnt[2]; i++)
		cout << 2;
	cout << endl;
	return 0;
}