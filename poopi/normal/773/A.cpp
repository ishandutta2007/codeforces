
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
#define Inf 1000000LL * 1000000LL * 2000000L
#define Mod 1000000007LL
int64 gcd(int64 a, int64 b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	int T;
	int64 x, y, p, q;
	for(cin >> T; T--; ){
		cin >> x >> y >> p >> q;
		if(p == q){
			cout << (x == y ? 0 : -1) << endl;
			continue;
		}
		if(p == 0){
			cout << (x == 0 ? 0 : -1) << endl;
			continue;
		}
		int64 l = (y + q - 1) / q;
		int64 r = Inf / q;
		while(l < r){
			int64 alpha = (l + r) / 2;
			int64 b = alpha * q - y;
			if(x <= alpha * p && alpha * p <= x + b)
				r = alpha;
			else l = alpha + 1;
		}

		cout << r * q - y << endl;
	}
	return 0;
}