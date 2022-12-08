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

int64 n, k;
int p;

char calc(int64 x, int64 dot, int64 cnt){
	if(dot > x){
		int64 rem = dot - x;
		if(rem % 2)
			rem++;
		dot -= rem;
		if(cnt <= rem)
			return '.';
		cnt -= rem;
	}
	if(cnt > 2 * dot)
		return 'X';
	return (cnt % 2 ? '.' : 'X');
}

int main(){
	while(cin >> n >> k >> p){
		int64 tmp;
		for(int i = 0; i < p; i++){
			cin >> tmp;
			cout << calc(k, n - k, tmp);
		}
		cout << endl;
	}
	return 0;
}