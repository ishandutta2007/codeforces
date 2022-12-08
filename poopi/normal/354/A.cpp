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

int n, l, r;
int ql, qr;
int w[1000010];
int sum = 0;

int main(){
	cin >> n >> l >> r >> ql >> qr;
	for(int i = 0; i < n; i++){
		cin >> w[i];
		sum += w[i];
	}
	int res = sum * r + (n - 1) * qr;
	int cur = 0;
	for(int i = 1; i <= n; i++){
		cur += w[i - 1];
		int tmp  = cur * l + (sum - cur) * r;
		if(i > n - i)
			tmp += ql * (i - (n - i) - 1);
		if(i < n - i)
			tmp += qr * ((n - i) - i - 1);
		res = min(res, tmp);
	}
	cout << res << endl;
	return 0;
}