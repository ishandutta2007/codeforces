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
int cnt[300];
string str;

int main(){
	cin >> n >> str;
	for(int i = 0; i < str.length(); i++)
		cnt[str[i] - 'A']++;
	sort(cnt, cnt + 300);
	reverse(cnt, cnt + 300);
	int64 p = 1;
	while(cnt[p] == cnt[0])
		p++;

	int64 res = 1;
	for(int i = 0; i < n; i++)
		res = (res * p) % Mod;
	cout << res << endl;
	return 0;
}