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
#define PLL pair<int64, int64>
#define Max 1000010

int64 cnt[Max];
int dv[Max];
bool npr[Max];

void find_prime(){
	for(int i = 2; i < Max; i++){
		if(!npr[i]){
			dv[i] = i;
			for(int j = 2 * i; j < Max; j += i)
				npr[j] = true, dv[j] = i;
		}
	}
}

int main(){
	find_prime();
	cnt[1] = 1;
	for(int i = 2; i < Max; i++){
		int c = 0, t = i;
		while(t % dv[i] == 0)
			t /= dv[i], c++;
		cnt[i] = cnt[t] * (c + 1); 
	}
	int a, b, c;
	cin >> a >> b >> c;
	int64 sum = 0;
	for(int i = 1; i <= a; i++)
		for(int j = 1; j <= b; j++)
			for(int k = 1; k <= c; k++)
				sum += cnt[i * j * k];
	cout << sum << endl;
    return 0;
}