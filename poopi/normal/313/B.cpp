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

int cnt[100010];
string str;

int main(){
	cin >> str;
	for(int i = 1; i < str.length(); i++)
		cnt[i] = cnt[i - 1] + (str[i] == str[i - 1] ? 1 : 0);
	int m, a, b;
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		cout << cnt[b - 1] - cnt[a - 1] << endl;
	}
    return 0;
}