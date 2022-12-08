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

int n, cnt, emp;
int64 fact[2010];
int64 c[2010][2010];
bool m1[100010];
bool m2[100010];


int main(){
	int a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a == -1){
			m1[i] = true;
			emp++;
		}
		else m2[a - 1] = true;
	}
	for(int i = 0; i < n; i++)
		if(m1[i] && !m2[i])
			cnt++;
	fact[0] = c[0][0] = 1;
	for(int i = 1; i <= n; i++){
		fact[i] = (fact[i - 1] * i) % Mod;
		c[i][i] = c[0][i] = 1;
		for(int j = 0; j < i; j++)
			c[j][i] = (c[j][i - 1] + c[j - 1][i - 1]) % Mod;
	}
	n = emp;
	int64 res = 0;
	for(int i = 0; i <= cnt; i++){
		int64 tmp = (c[i][cnt] * fact[n - i]) % Mod;
		if(i & 1)
			res = (res - tmp + Mod) % Mod;
		else res = (res + tmp) % Mod;
	}
	cout << res << endl;
	return 0;
}