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

int n, k, ini;
set <int> st;
char str[9];

void solve(int val, int rem){
	if(rem == 0){
		int dif = abs(abs(val) - n);
		if(dif < 10000 && st.size() < k)
			st.insert(dif * 10000 + ini);
		if(dif < 10000 && st.size() < k)
			st.insert(ini * 10000 + dif);
		return;
	}
	int p = 10;
	solve(val + rem % p, rem / p);
	solve(val - rem % p, rem / p);
	solve(val * (rem % p), rem / p);
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < 10000; i++){
		ini = i;
		solve(i % 10, i / 10);
	}
	for(set <int>::iterator it = st.begin(); it != st.end(); it++)
		printf("%08d\n", *it);
	return 0;
}