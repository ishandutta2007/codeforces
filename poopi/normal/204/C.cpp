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

int n;
string s1, s2;
int64 bef[200010][30];
int64 nex[200010][30];

int main(){
	std::ios::sync_with_stdio(false);
	cin >> n >> s1 >> s2;
	for(int i = 0; i < n; i++){
		bef[i][s1[i] - 'A'] += i + 1;
		for(int j = 0; j < 26; j++)
			bef[i + 1][j] = bef[i][j];
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++)
			nex[i][j] = nex[i + 1][j];
		nex[i][s1[i] - 'A'] += n - i;
	}

	int64 tot = 0;
	for(int64 i = 1; i <= n; i++)
		tot += i * i;

	double ans = 0;
	for(int i = 0; i < n; i++){
		int idx = s2[i] - 'A';
		ans += (double)(bef[i][idx] * (n - i) + nex[i + 1][idx] * (i + 1)) / tot;
	}

	cout << setprecision(9) << fixed << (double)ans << endl;
	return 0;
}