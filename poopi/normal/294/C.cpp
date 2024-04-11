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
int idx[1010];
int64 fact[1010];
vector <int> sz;

int64 modP(int64 x, int64 y, int64 z){
	int64 ret = 1;
	while(y){
		if(y & 1)
			ret = (ret * x) % Mod;
		x = (x * x) % Mod;
		y >>= 1;
	}
	return ret;
}

int main(){
	fact[0] = 1;
	for(int i = 1; i <= 1000; i++)
		fact[i] = (fact[i - 1] * i) % Mod;
	cin >> n >> k;
	for(int i = 0; i < k; i++)
		cin >> idx[i];
	sort(idx, idx + k);
	sz.push_back(idx[0] - 1);
	sz.push_back(n - idx[k - 1]);
	int tot = n - idx[k - 1] + idx[0] - 1;
	int64 res = 1;
	for(int i = 1; i < k; i++){
		sz.push_back(idx[i] - idx[i - 1] - 1);
		tot += sz.back();
		for(int j = 1; j < sz.back(); j++)
			res = (res * 2) % Mod;
	}
	res = (res * fact[tot]) % Mod;
	for(int i = 0; i < sz.size(); i++)
		res = (res * modP(fact[sz[i]], Mod - 2, Mod)) % Mod;
	cout << res << endl;
	return 0;
}