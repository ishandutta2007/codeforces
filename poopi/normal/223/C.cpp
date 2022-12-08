										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Mod 1000000007LL
int n;
int64 k;
int64 arr[2010];
int64 res[2010];

int64 modP(int64 x, int64 y, int64 z){
	int64 ret = 1;
	while(y){
		if(y & 1)
			ret = (ret * x) % z;
		x = (x * x) % z;
		y >>= 1;
	}
	return ret;
}

int C(int64 a, int64 b){
	if(a == 0 || a == b)
		return 1;
	if(a > b)
		return 0;
	int64 ret = 1;
	for(int i = b; i > b - a; i--)
		ret = (ret * i) % Mod;
	for(int i = a; i > 0; i--)
		ret = (ret * modP(i, Mod - 2, Mod)) % Mod;
	return ret;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			res[j] = (res[j] + arr[j - i] * C(i, i + k - 1)) % Mod;
	for(int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << endl;
	return 0;
}