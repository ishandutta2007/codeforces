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

int s[10], e[10];

int main(){
	int str, end;
	while(cin >> str >> end){
		int sz = 0;
		while(str != 0 || end != 0){
			s[sz] = str % 10;
			str /= 10;
			e[sz] = end % 10;
			end /= 10;
			sz++;
		}
		int64 res = 0, rev = 0;
		int64 tl = 0, tr = 0;
		for(int i = sz - 1; i >= 0; i--){
			tl = tl * 10 + s[i];
			tr = tr * 10 + e[i];
			int64 mx = -1, b = -1, br = -1;
			for(int j = 0; j <= 9; j++){
				int64 t = res * 10 + j;
				int64 trev = rev * 10 + 9 - j;
				if(t < tl || t > tr)
					continue;
				if(mx == -1 || mx < t * trev){
					b = t;
					br = trev;
					mx = t * trev;
				}
			}
			res = b;
			rev = br;
		}
		cout << res * rev << endl;
	}
	return 0;
}