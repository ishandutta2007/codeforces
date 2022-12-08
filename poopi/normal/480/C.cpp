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

int n, k, a, b;
int64 cnt[6000];
int64 sum[6000];

int main(){
	cin >> n >> a >> b >> k;
	int st;
	if(a > b){
		n -= b;
		st = a - b;
	}
	else{
		n = b - 1;
		st = b - a;
	}
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		cnt[i] = 1;
		sum[i] = sum[i - 1] + cnt[i];
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			cnt[j] = (sum[min(n, 2 * j - 1)] - cnt[j] + Mod) % Mod;
			sum[j] = (sum[j - 1] + cnt[j]) % Mod;
		}
	}
	cout << cnt[st] << endl;
	return 0;
}