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

int n, k;
int64 pw[100010];
int64 fact[100010];
int64 s[100010];
string str;

int64 modP(int64 x, int64 y){
	int64 ret = 1;
	while(y){
		if(y % 2)
			ret = (ret * x) % Mod;
		x = (x * x) % Mod;
		y /= 2;
	}
	return ret;
}

int64 sel(int64 a, int64 b){
	if(a < 0 || a > b)
		return 0;
	int64 res = fact[b];
	res = (res * modP(fact[a], Mod - 2)) % Mod;
	res = (res * modP(fact[b - a], Mod - 2)) % Mod;
	return res;
}

int main(){
	cin >> n >> k >> str;
	reverse(str.begin(), str.end());
	pw[0] = 1;
	fact[0] = 1;
	for(int i = 1; i <= n; i++){
		pw[i] = (pw[i - 1] * 10) % Mod;
		fact[i] = (fact[i - 1] * i) % Mod;
	}

	int64 res = (sel(k, n - 1) * (str[0] - '0')) % Mod;
	for(int i = 1; i < n; i++){
		s[i] = (s[i - 1] + pw[i - 1] * sel(k - 1, n - 1 - i)) % Mod;
		int64 t = (s[i] + pw[i] * sel(k, n - 1 - i)) % Mod;
		res = (res + t * (str[i] - '0')) % Mod;
	}
	cout << res << endl;
	return 0;
}