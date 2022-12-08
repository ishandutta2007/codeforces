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

int n, c[5];
int tot = 0;

int main(){
	cin >> n;
	int a;
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		c[a]++;
		tot += a;
	}
	if(tot == 1 ||  tot == 2 || tot == 5){
		cout << -1 << endl;
		return 0;
	}

	int cnt = 0;
	int t = min(c[1], c[2]);
	c[1] -= t, c[2] -= t;
	cnt += t, c[3] += t;

	t = c[1] / 3;
	c[1] -= 3 * t;
	c[3] += t;
	cnt += 2 * t;

	if(c[1] != 0){
		if(c[1] == 1 && c[3] > 0)
			cnt++;
		else cnt += 2;
	}

	t = c[2] / 3;
	c[2] -= 3 * t;
	c[3] += 2 * t;
	cnt += 2 * t;

	if(c[2] != 0){
		if(c[2] == 1 && c[4] > 0)
			cnt++;
		else cnt += 2;
	}

	cout << cnt << endl;
	return 0;
}