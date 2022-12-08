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

int m;
string str;
int cnt[100010][3];

int main(){
	cin >> str >> m;
	cnt[0][str[0] - 'x'] = 1;
	for(int i = 1; i < str.length(); i++){
		for(int j = 0; j < 3; j++)
			cnt[i][j] = cnt[i - 1][j];
		cnt[i][str[i] - 'x']++;
	}
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		if(b - a < 2){
			cout << "YES" << endl;
			continue;
		}
		int t1 = cnt[b][0] - (a == 0 ? 0 : cnt[a - 1][0]);
		int t2 = cnt[b][1] - (a == 0 ? 0 : cnt[a - 1][1]);
		int t3 = cnt[b][2] - (a == 0 ? 0 : cnt[a - 1][2]);
		int mx = max(t1, max(t2, t3));
		int mn = min(t1, min(t2, t3));
		cout << (mx - mn < 2 ? "YES" : "NO") << endl;
	}
	return 0;
}