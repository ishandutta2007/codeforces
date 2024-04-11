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

int cnt[10000];

int main(){
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	cnt[0] = 0;
	for(int i = 1; i <= n; i++){
		cnt[i] = -1000000;
		if(i >= a) cnt[i] = max(cnt[i], cnt[i - a] + 1);
		if(i >= b) cnt[i] = max(cnt[i], cnt[i - b] + 1);
		if(i >= c) cnt[i] = max(cnt[i], cnt[i - c] + 1);
	}
	cout << cnt[n] << endl;
    return 0;
}