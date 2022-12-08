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

bool f[20];

bool ok(int num){
	memset(f, false, sizeof f);
	while(num){
		int d = num % 10;
		num /= 10;
		if(f[d]) return false;
		f[d] = true;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	int res = n + 1;
	while(!ok(res))
		res++;
	cout << res << endl;
	return 0;
}