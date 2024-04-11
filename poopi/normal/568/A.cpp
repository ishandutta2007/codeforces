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
#define Max 20000000

bool npr[Max];
bool isPal[Max];
int pi[Max], rub[Max];

void init(){
	npr[0] = npr[1] = true;
	for(int i = 2; i < Max; i++){
		if(!npr[i]){
			for(int j = 2 * i; j < Max; j += i)
				npr[j] = true;
		}
	}
	for(int i = 1; i < 10000; i++){
		bool fir = true;
		int x = i;
		int a = i, b = i;
		while(x){
			int d = x % 10;
			x /= 10;
			a = a * 10 + d;
			if(!fir)
				b = b * 10 + d;
			fir = false;
		}
		if(a < Max)
			isPal[a] = true;
		if(b < Max)
			isPal[b] = true;
	}
}

int64 p, q;

int main(){
	init();
	pi[0] = rub[0] = 0;
	for(int i = 1; i < Max; i++){
		pi[i] = pi[i - 1] + (npr[i] ? 0 : 1);
		rub[i] = rub[i - 1] + (isPal[i] ? 1 : 0);
	}

	cin >> p >> q;
	int res = 0;
	for(int i = 1; i < Max; i++)
		if(pi[i] * q <= p * rub[i])
			res = i;
	cout << res << endl;
	return 0;
}