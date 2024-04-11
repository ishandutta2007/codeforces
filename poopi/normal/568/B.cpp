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
#define Max 4010

int n;
int64 fact[Max];
int64 rfact[Max];
int64 B[Max];

int64 modP(int64 x, int64 y, int64 z){
	int64 ret = 1;
	while(y){
		if(y % 2)
			ret = (ret * x) % z;
		x = (x * x) % z;
		y /= 2;
	}
	return ret;
}

int main(){
	rfact[0] = fact[0] = 1;
	for(int i = 1; i < Max; i++){
		fact[i] = (fact[i - 1] * i) % Mod;
		rfact[i] = (rfact[i - 1] * modP(i, Mod - 2, Mod)) % Mod;
	}

	B[0] = 1;
	for(int i = 1; i < Max; i++){
		B[i] = 0;
		for(int j = 0; j < i; j++){
			int64 tmp = (fact[i - 1] * rfact[j]) % Mod;
			tmp = (tmp * rfact[i - 1 - j]) % Mod;
			B[i] = (B[i] + tmp * B[j]) % Mod;
		}
	}

	cin >> n;
	int64 res = 0;
	for(int i = 1; i <= n; i++){
		int64 cnt = (fact[n] * rfact[n - i]) % Mod;
		cnt = (cnt * rfact[i]) % Mod;
		cnt = (cnt * B[n - i]) % Mod;
		res = (res + cnt) % Mod;
	}
	cout << res << endl;
	return 0;
}