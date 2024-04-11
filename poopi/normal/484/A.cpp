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

int main(){
	int T;
	int64 l, r;
	for(cin >> T; T--; ){
		cin >> l >> r;
		int64 tmp = 0, ans = 0;
		int cnt = 0, best = 0;
		for(int i = 60; i >= 0; i--){
			if(!(r & (1LL << i)))
				continue;
			if(!(l & (1LL << i))){
				if(cnt + i > best){
					ans = tmp + (1LL << i) - 1;
					best = cnt + i;
				}
				l = 0;
			}
			cnt++;
			tmp += (1LL << i);
			if(cnt > best){
				ans = tmp;
				best = cnt;
			}
		}
		cout << ans << endl;
	}
	return 0;
}